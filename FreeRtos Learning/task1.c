#include <lpc21xx.h>

#include "freeRTOS.h"
#include "task.h"
static void vLEDBlinkTask(void *pvParams);
static void vBuzzerTask(void *pvParams);
static void vLEDBlinkTask2(void *pvParams);

void delay(int ct)
{
	int i,j;
	for(i=0;i<ct;i++)
		for(j=0;j<5000;j++);
}

void setupHardware(void)
{
	IODIR1 = IODIR1 | (0xff<<17);
	IODIR1 = IODIR1 | (0xff<<19);
	IODIR0 = IODIR0 | (1<<11);
	IOCLR1 = (0xff << 17);
	//delay(1000);

	
	IOCLR1 = (0xff << 19);
	IOCLR0 = (1 << 11);
	//delay(1000);

   	
//	IOCLR0 = (1 << 11);
	delay(1000);
}

void vLEDBlinkTask(void *pvParams)
{
	int ct = 0;
	while(1)
	{
		ct++;
		if(!(ct % 10)) 
			vTaskDelay(3000);
		IOSET1 = (1<<17);
		delay(500);
		IOCLR1 = (1<<17);
		delay(500);
	}
}
void vLEDBlinkTask2(void *pvParams)
{
	int ct = 0;
	while(1)
	{
		ct++;
		if(!(ct % 10)) 
			vTaskDelay(3000);
		IOSET1 = (1<<19);
		delay(500);
		IOCLR1 = (1<<19);
		delay(500);
	}
}
void vBuzzerTask(void *pvParams)
{
	int ct = 0;
	while(1)
	{
		ct++;
		if(!(ct % 10)) 
			vTaskDelay(3000);
		IOSET0 = (1<<11);
		delay(500);
		IOCLR0 = (1<<11);
		delay(500);
	}
}
 // vTaskDelay make schedular to envoked or not it will follow in this case as order for task is t3,t1,t2
int main()
{
	setupHardware();
	xTaskCreate(vLEDBlinkTask, "BLINK_TASK", 100, NULL, 1, NULL);
	xTaskCreate(vBuzzerTask, "BUZZER_TASK", 100, NULL, 1, NULL);
	xTaskCreate(vLEDBlinkTask2, "BLINK_TASK2", 100, NULL, 1, NULL);
	vTaskStartScheduler();		// this enables multitasking
	for( ;; );
}
