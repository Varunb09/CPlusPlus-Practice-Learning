//code for implementation of all the IPC's
//header file for thread system calls
#include<pthread.h>

//Standard C header files 
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

//header files for IPC system calls 
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
// customised action prototype
void action(int);
//threads prototype
void* thread1(void *x);
void* thread2(void *x);
void* thread3(void *x);
//initialization of mutex
int num=1;
pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t mycond=PTHREAD_COND_INITIALIZER;


int main()
{
	// initailizing pipe parameters
	int fd[2];
	//creating unnamed pipe
	int a = pipe(fd);	
	if(a==-1)
		perror("pipe");
        else
	{
		printf("***********pipe created sucessfully************\n");			
		printf("Writing end of the pipe fd[0] : %d\n",fd[0]);
		printf("Reading end of the pipe fd[1] : %d\n",fd[1]);
	}

	//register the signal   	
	signal(SIGCHLD,action);							
	printf("parent id=%d\n",getpid());
	
	int ret=fork();
	if(ret==0)
	{	

		//signal
		printf("***********entering into child process************\n");
		printf("current process id=%d\n",getpid());	`		// process id parameters
                printf("parent id=%d\n",getppid());
                printf("user id=%d\n",getuid());
                printf("group id=%d\n",getgid());

		//pipe
		char buff_w[]="hi parent\n";					//sending data to pipe
                int w = write(fd[1],buff_w,sizeof(buff_w));
                if(w==-1)
                	perror("write");
                else

 	        {	
			printf("number of bytes written into the pipe :%d\n",w);
			printf("Content written into the pipe : %s\n",buff_w);
		}

		//file1 code 
		int i;
		printf("**********creation of file1 **********\n");  		         
		int fd1 = open("file1.txt",O_RDWR | O_CREAT,0666);	    //Opening / creating file.txt
		if(fd1 == -1)						    //checking for failure case
		{
			perror("open fail:");
		}	
		else							    //for success case
		{
			char buff1[50];					    	
			printf("Enter your msg for file 1:\n");
			__fpurge(stdin);
			gets(buff1);
			int w1 = write(fd1,buff1,sizeof(buff1));	   //to write in file.txt system call
			if(w1 == -1)
				perror("write fail:");
			else
			{
				printf("file1 write done success\n");
				int fd2 = open("file1.txt",O_RDONLY);
				if(fd2 == -1)
				{
					perror("open fail:");
				}	
				else
				{
					//printf("write already done\n");
					char buff2[50];
					int r1 = read(fd2,buff2,50);      //to read data in file.txt system call
					if( r1 == -1)
					{
						perror("read fail:");
					}
					else
					{
						
						buff2[r1]='\0';
						printf("File1 Content read success = %s\n",buff2);

						//Creating shared memory of 150 bytes
						//storing data to shared memory using semaphore 
						int key1 = 10;						//shared memory key
						int shmid = shmget(key1,150,IPC_CREAT|0666);
						int key =100,ret,i;					//semaphore key
						int semid = semget(key,1,IPC_CREAT | 0666);		//getting semaphore
						if(semid == -1)
							perror("semget") ;
						else
						{
							ret = semctl(semid,0,SETVAL,1);		//Initialize the semaphore system call
							if(ret == -1)
								perror("semctl");
							else
							{
								struct sembuf x = {0,-1,0};     	
								ret = semop(semid,&x,1);	//Acquiring semaphore system call
								if(ret == -1)
									perror("semop");
								else
								{	
									printf("**************File-1 semaphore locked***************\n");
									int  *ptr1 = (int*)shmat(shmid,NULL,0);
									if(ptr1)
									{
										//writing data to respective shared memory
										for(i=0;buff2[i]!='\0';i++)
										{
				
											*ptr1 = buff2[i];
											ptr1++;
										}
										printf("data written in shared memory(0-50 bytes) is :%s \n",buff2);
										shmdt(ptr1);
									}
									else
										perror("shmat");
								}	
							}
						}
						close(fd1);
						close(fd2);
					}
				}
			}
		}



	//file 2 code
	printf("**********creation of file2**********\n");
	int fd3 = open("file2.txt",O_RDWR | O_CREAT,0666);
	if(fd3 == -1)
	{
		perror("open fail:");
	}	
	else
	{
		char buff3[50];
		printf("Enter your msg for file 2:\n");
		__fpurge(stdin);
		gets(buff3);
		int w2 = write(fd3,buff3,sizeof(buff3));
		if(w2 == -1)
			perror("write fail:");
		else
		{
			printf("file2 write done success\n");
			int fd4 = open("file2.txt",O_RDONLY);
			if(fd4 == -1)
			{
				perror("open fail:");
			}	
			else
			{
				//printf("write already done\n");
				char buff4[50];
				int r2 = read(fd4,buff4,50);
				if( r2 == -1)
				{
					perror("read fail:");
				}
				else
				{
					buff4[r2]='\0';
					printf("File2 Content read success = %s\n",buff4);

					//storing data to shared memory using semaphore

					int key1 = 10;					//shared memory key
					int shmid = shmget(key1,150,IPC_CREAT|0666);
					int key =100,ret,i;				//semaphore key
					int semid = semget(key,1,IPC_CREAT | 0666);	//getting semaphore
					if(semid == -1)
						perror("semget") ;
					else
					{
						ret = semctl(semid,0,SETVAL,1);			//initializing semaphore
						if(ret == -1)
							perror("semctl");
						else
						{
							struct sembuf x = {0,-1,0};
							ret = semop(semid,&x,1);		//aquiring semaphore
							if(ret == -1)
								perror("semop");
							else
							{	
								printf("**************File-2 semaphore locked***************\n");
								int *ptr2 = (int*)shmat(shmid,NULL,0);
								if(ptr2)
								{
									ptr2 += 50;
									//writing data to respective shared memory
									for(i=0;buff4[i]!='\0';i++)
									{
						
										*ptr2 = buff4[i];
										ptr2++;
									}
										printf("data written in shared memory(50-100 bytes) is :%s\n",buff4);
									shmdt(ptr2);				
								}
								else
									perror("shmat");
							}	
						}
					}
					close(fd3);
					close(fd4);
				}
			}
		}
	}




	//file 3 code
	printf("**********creation of file3**********\n");
	int fd5 = open("file3.txt",O_RDWR | O_CREAT,0666);
	if(fd5 == -1)
	{
		perror("open fail:");
	}	
	else
	{
		char buff5[50];
		printf("Enter your msg for file 3:\n");
		__fpurge(stdin);
		gets(buff5);
		int w3 = write(fd5,buff5,sizeof(buff5));
		if(w3 == -1)
			perror("write fail:");
		else
		{
			printf("file3 write done success\n");
			int fd6 = open("file3.txt",O_RDONLY);
			if(fd6 == -1)
			{
				perror("open fail:");
			}	
			else
			{
				//printf("write already done\n");
				char buff6[50];
				int r3 = read(fd6,buff6,50);
				if( r3 == -1)
				{
					perror("read fail:");
				}
				else
				{
					buff6[r3]='\0';
			                printf("File2 Content read success = %s\n",buff6);

					//storing data to shared memory using semaphore

					int key1 = 10;        					//shared memory key
					int shmid = shmget(key1,150,IPC_CREAT|0666);
					int key =100,ret,i;					//semaphore key
					int semid = semget(key,1,IPC_CREAT | 0666);		//getting semaphore
					if(semid == -1)
						perror("semget") ;
					else
					{
						ret = semctl(semid,0,SETVAL,1);			//initializing semaphore
						if(ret == -1)
							perror("semctl");
						else
						{
							struct sembuf x = {0,-1,0};
							ret = semop(semid,&x,1);		//aquiring semaphore
							if(ret == -1)
								perror("semop");
							else
							{	
								printf("**************File-3 semaphore locked***************\n");
								int *ptr3 = (int*)shmat(shmid,NULL,0);
								if(ptr3)
								{
									ptr3 += 100;
									//writing data to respective shared memory
									for(i=0;buff6[i]!='\0';i++)
									{
						
										*ptr3 = buff6[i];
										ptr3++;
									}
									printf("data written in shared memory(100-150 bytes) is :%s\n",buff6);
									printf("***********Child process terminated****************\n\n");
									shmdt(ptr3);				
								}
								else
									perror("shmat");
							}	
						}
					}
					close(fd5);
					close(fd6);
				}
			}
		}
	}
}

		
	else
	{
		wait(0);
		printf("******************PIPE DATA RECIEVED IN PARENT PROCESS***********************\n");
		printf("Current running process id=%d\n",getpid());			//ongoing process information
		printf("child id=%d\n",ret);
		printf("parent id=%d\n",getppid());
		printf("user id=%d\n",getuid());
		printf("group id=%d\n",getgid());
		//pipe
		char buff_r[20];
                int r=read(fd[0],buff_r,sizeof(buff_r));
                if(r==-1)
                	perror("read");
                else
                {
                        buff_r[20]='\0';						// retreaving pipe data
 	       		printf("number of bytes read from the pipe :%d\n",r);
                        printf("content from pipe : %s\n",buff_r);
                }

		//thread
		pthread_t tid1,tid2,tid3;				//invoking 3 threads using pthread_create() system call
		pthread_create(&tid1,NULL,thread1,0);
		pthread_create(&tid2,NULL,thread2,0);
		pthread_create(&tid3,NULL,thread3,0);
		pthread_join(tid1,0);					//Joining 3 threads using pthread_join() system call
		pthread_join(tid2,0);
		pthread_join(tid3,0);
		pthread_exit(NULL);					//exiting the thread using pthread_exit() system call
	}
}
void action(int a)							// customized signal action definatyion
{
	printf("***********Entering into parent process***********\n");		
	printf("**********customized action***********\n");
	printf("signal received : %d\n\n",a);
}
void* thread1(void *x)
{
	sleep(1);
	printf("***********Entering into thread-1*****************\n");
	printf("Accessing (100-150 bytes) of shared memory data\n");
	pthread_mutex_lock(&mymutex);					//Acquiring the mutex
	int key1 = 10,*y;
	int shmid = shmget(key1,150,IPC_CREAT|0666);			//acquiring shared memory from 100 - 150 bytes
	int  *ptr3 = (int*)shmat(shmid,NULL,0);
	if(ptr3)
	{
		int i;
		// reading data from respective shared memory
		y =ptr3+100;
		printf("content read from the shared memory:");
		for(i=0;i<50;i++)
		{
			printf("%c",*y);
			y++;
		}
		printf("\n");
		shmdt(ptr3);
	}
	else
	{
	perror("shmat");
	}
	pthread_mutex_unlock(&mymutex);						//realeasing mutex
	printf("**************Exiting thread-2************\n");
	pthread_exit(NULL);

}

void* thread2(void *x)
{
	sleep(2);
        printf("***********Entering into thread-2*****************\n");
	printf("Accessing (0-50 bytes) of shared memory data\n");
        pthread_mutex_lock(&mymutex);						//Acquiring the mutex
	int key1 = 10;
	int shmid = shmget(key1,150,IPC_CREAT|0666);				//acquiring shared memory from 0 - 50 bytes
	int  *ptr1 = (int*)shmat(shmid,NULL,0);
        if(ptr1)
	{
		int i;
		// reading data from respective shared memory
		printf("content read from the shared memory:");
		for(i=0;i<50;i++)
		{
			printf("%c",*ptr1);
			ptr1++;
		}
		printf("\n");
		shmdt(ptr1);
	}
	else
	{
	perror("shmat");
	}
        pthread_mutex_unlock(&mymutex);						//realeasing mutex
        printf("**************Exiting thread-2************\n");
        pthread_exit(NULL);

	
}

void* thread3(void *x)
{	
	int i;
        printf("***********Entering into thread-3*****************\n");
	printf("Accessing (50-100 bytes) of shared memory data\n");
        pthread_mutex_lock(&mymutex);							//Acquiring the mutex
	int key1 = 10,*y;
	int shmid = shmget(key1,150,IPC_CREAT|0666);					//acquiring shared memory from 0 - 50 bytes
	int  *ptr2 = (int*)shmat(shmid,NULL,0);
       if(ptr2)
	{
		int i;
		// reading data from respective shared memory
		y = ptr2+50;
		printf("content read from the shared memory:");
		for(i=0;i<50;i++)
		{
		printf("%c",*y);
		y++;
		}
		printf("\n");
		shmdt(ptr2);
	}
	else
	{
	perror("shmat");
	}
				
        pthread_cond_signal(&mycond);
        pthread_mutex_unlock(&mymutex);							//realeasing mutex
        printf("**************Exiting thread-3************\n");
        pthread_exit(NULL);

}
