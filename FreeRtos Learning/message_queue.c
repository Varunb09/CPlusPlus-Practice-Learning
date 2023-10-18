	   
#include <lpc21xx.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Application includes */
//#include "..\lcdheader.h"
//#include "..\libh.h"
#include "lcd link.h"

/** globals **/
TaskHandle_t pS1Task, pS2Task, pRTask;

/* function prototypes */
void setupHardware(void);
static void vSenderTask1(void *pvParams);
static void vSenderTask2(void *pvParams);
static void vRcvTask(void *pvParams);

QueueHandle_t xQueue;
		 
int main()	 {
	setupHardware();
	/* Create the queue, Qlength = 3, itemsize = 5*/
	xQueue = xQueueCreate( 3, 5 );
	xTaskCreate( vSenderTask1, "sender1", configMINIMAL_STACK_SIZE, NULL, 3, &pS1Task );
	xTaskCreate( vSenderTask2, "sender2", configMINIMAL_STACK_SIZE, NULL, 2, &pS2Task );
	xTaskCreate( vRcvTask, "receiver", configMINIMAL_STACK_SIZE, NULL, 1, &pRTask );

	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}

void setupHardware(void) 
{
	 //IODIR1 |= LED_ALL; // leds
	 IODIR1 = IODIR1 | (0xff<<17);
	 //IODIR0 |= BUZZER; //buzzer
	 IODIR0 = IODIR0 | (1<<11);
	 //IOCLR1 = LED_ALL;
	 IOCLR1 = (0xff << 17);
	 lcd();
}	
void vSenderTask1(void *pvParameters)
{
	BaseType_t ret;
	ret = xQueueSendToBack( xQueue, "M1", portMAX_DELAY );	 // INCLUDE_vTaskSuspend set to 1
	ret = xQueueSendToFront( xQueue, "M2", portMAX_DELAY );	 //	for wait-forever timeout option
	ret = xQueueSendToFront( xQueue, "M3", portMAX_DELAY );
	ret = xQueueSendToBack( xQueue, "M4", portMAX_DELAY );
	vTaskSuspend(NULL);
 	while(1)	 {
		IOSET1 = (1<<21);
		delay(300);
		IOCLR1 = (1<<21);
		delay(300);
	}
}

void vSenderTask2(void *pvParameters)
{
	BaseType_t ret;
	ret = 	xQueueSendToFront( xQueue, "M5", portMAX_DELAY );	 // INCLUDE_vTaskSuspend set to 1
	//if (ret == pdPASS) lcd_num(2);
	ret =  xQueueSendToBack( xQueue, "M6", portMAX_DELAY );	 //	for wait-forever timeout option
	//if (ret == pdPASS) lcd_num(2);
	ret = xQueueSendToFront( xQueue, "M7", portMAX_DELAY );
	//if (ret == pdPASS) lcd_num(2);

	vTaskSuspend(NULL);
	while (1)
	{
		IOSET1 = (1<<17);
		delay(300);
		IOCLR1 = (1<<17);
		delay(300);
	}
}
				
void vRcvTask(void *pvParameters)
{	
	char buff[10] ="hello";
	BaseType_t ret;
	while (1)
	{
		ret = xQueueReceive(xQueue, buff, portMAX_DELAY);
		if(ret == pdPASS)  
		{
			IOSET0 = (1<<11);	
			delay(400);
			IOCLR0 = (1<<11);
			delay(400);
			lcd_string(buff);
			command(0x01);
		}
		else 
		{
			data1("Err");
			command(0x01);
		}
	}
}
