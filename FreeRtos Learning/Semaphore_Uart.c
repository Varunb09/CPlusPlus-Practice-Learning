//#define configUSE_PREEMPTION	in (FreeRTOSConfig.h)  	1  is changed to 0 for avoiding preemption of task
// Add lcd link.h to run this
#include <lpc21xx.h>								 		

#include "freeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "lcd link.h"

//void vSemaphoreCreateBinary( SemaphoreHandle_t xSemaphore );
//BaseType_t xSemaphoreGive( SemaphoreHandle_t xSemaphore );
//BaseType_t xSemaphoreTake( SemaphoreHandle_t xSemaphore, TickType_t xTicksToWait );
SemaphoreHandle_t xSemaphore;
static void vConsumerTask(void *pvParams);
static void vProducerTask(void *pvParams);

int ct = 0;


void vProducerTask(void *pvParams)
{

	while(1)
	{
		ct++;
		xSemaphoreGive( xSemaphore );
	}
}

void vConsumerTask(void *pvParams)
{
	TickType_t xTicksToWait=500;
	while(1)
	{
		xSemaphoreTake( xSemaphore,xTicksToWait );
		command(0x01);
		display(ct);

	}
}
int main()
{
	lcd();
	//setupHardware();
	xSemaphore = xSemaphoreCreateBinary();
	xTaskCreate(vConsumerTask, "CONSUMER_TASK", 100, NULL, 2, NULL);
	xTaskCreate(vProducerTask, "PRODUCER_TASK", 100, NULL, 1, NULL);

	vTaskStartScheduler();		// this enables multitasking
	for( ;; );
}
