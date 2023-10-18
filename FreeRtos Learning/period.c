//#define configUSE_PREEMPTION		1  is changed to 0 for avoiding preemption of task
#include <lpc21xx.h>								 		

#include "freeRTOS.h"
#include "task.h"
static void vLEDBlinkTask(void *pvParams);
static void vBuzzerTask(void *pvParams);

void delay(int ct)
{
	int i,j;
	for(i=0;i<ct;i++)
		for(j=0;j<5000;j++);
}

void setupHardware(void)
{
	IODIR1 = IODIR1 | (0xff<<17);

	IODIR0 = IODIR0 | (1<<11);
	IOCLR1 = (0xff << 17);
	//delay(1000);

	
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
	
		IOSET1 = (1<<17);
		delay(500);
		IOCLR1 = (1<<17);
		delay(500);
	}
}

void vBuzzerTask(void *pvParams)
{
	TickType_t xLastWakeTime;
	int i = 0;
	const TickType_t xPeriod = pdMS_TO_TICKS(3000);

	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		// produce a delay of 3 second along with previous wake up time when it is to be actually schedule
		// so it maintained perfect time period for invoking the task
		vTaskDelayUntil(&xLastWakeTime, xPeriod);
		i++;
		IOSET0 = (1<<11);
		delay(200);
		IOCLR0 = (1<<11);
		delay(200);
	}
}
int main()
{
	setupHardware();
	xTaskCreate(vLEDBlinkTask, "BLINK_TASK", 100, NULL, 1, NULL);
	xTaskCreate(vBuzzerTask, "BUZZER_TASK", 100, NULL, 2, NULL);

	vTaskStartScheduler();		// this enables multitasking
	for( ;; );
}
