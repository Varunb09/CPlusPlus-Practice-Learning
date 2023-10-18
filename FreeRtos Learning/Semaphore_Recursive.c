//#define configUSE_PREEMPTION	in (FreeRTOSConfig.h)  	1  is changed to 0 for avoiding preemption of task
// Add lcd link.h to run this
#include <lpc21xx.h>								 		

#include "freeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "lcd link.h"


SemaphoreHandle_t xSemaphore;
//TickType_t xTicksToWait=0;
UBaseType_t uxCreatedPriority;

static void vTask2(void *pvParams);
static void vTask1(void *pvParams);
static void vTask3(void *pvParams);


void vTask1(void *pvParams)
{
   	xSemaphoreTake( xSemaphore,portMAX_DELAY );
	command(0x01);
	data1("In TASK_1_");
	xTaskCreate(vTask2, "TASK2", 100, NULL, 3, NULL);
	delay(200);

	command(0x01);
	delay(200);

	uxCreatedPriority = uxTaskPriorityGet( NULL );
	data(uxCreatedPriority + 48);
	delay(200);
	while(1)
	{
		
		command(0x01);
		data1("TASK_1_");
		delay(200);
		
		
		//uxCreatedPriority = uxTaskPriorityGet( NULL );
		delay(7000);
	//	xSemaphoreGive( xSemaphore );
		
	}
}

void vTask2(void *pvParams)
{
	command(0x01);
	data1(" In TASK_2_");
	xTaskCreate(vTask3, "TASK3", 100, NULL, 2, NULL);
	xSemaphoreTake( xSemaphore,portMAX_DELAY );
	
	while(1)
	{
		command(0x01);
		data1("TASK_2_");
		
	//	xSemaphoreGive( xSemaphore );
	}
}
void vTask3(void *pvParams)
{
	IODIR1 = IODIR1 | (0xff<<17);
	IOCLR1 = (0xff << 17);
	command(0x01);
	data1("In TASK_3_");
	
	
	while(1)
	{
		IOSET1 = (1<<17);
		delay(500);
		IOCLR1 = (1<<17);
		delay(500);
		
	}
}
int main()
{
	lcd();
	//setupHardware();
	// using mutex, it block both middle and high priority and execute low priority task
	xSemaphore = xSemaphoreCreateMutex();
	// // using create binary semphore makes middle priority enable and low priority will blocked for ever
//	xSemaphore = xSemaphoreCreateBinary();
//	xSemaphoreGive( xSemaphore );
	xTaskCreate(vTask1, "TASK1", 100, NULL, 1, NULL);
	vTaskStartScheduler();		// this enables multitasking
	for( ;; );
}
