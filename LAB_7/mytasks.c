
#include <avr/pgmspace.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "LED.h"
#include "button.h"
#include "lcd_lib.h"
#include "mytasks.h"
#include "freertosm128.h"
void vLEDFlashTask( void *pvParameters )
{
vLEDInit();
portTickType xLastWakeTime;
const portTickType xFrequency = 1000;
xLastWakeTime=xTaskGetTickCount();
	for( ;; )
	{
		vLEDToggle();
		vTaskDelayUntil(&xLastWakeTime,xFrequency);		
	}
	
}
void vButtonCheckTask( void *pvParameters )
{
portTickType xLastWakeTime;
const portTickType xFrequency = 20;
xLastWakeTime=xTaskGetTickCount();
xSemaphoreTake(xButtonSemaphore, (portTickType)0);
vButtonInit();
	for (;;)
	{
	if (xButtonGetStatus()==pdTRUE)
		{
			xSemaphoreGive(xButtonSemaphore);
		}
	vTaskDelayUntil(&xLastWakeTime,xFrequency);	
	}
}
void vLCDUpdateTask( void *pvParameters )
{
static const uint8_t welcomeln1[] PROGMEM="PLUGARU T LAB7";
static const uint8_t buttonln1[] PROGMEM="BT:";
static const uint8_t tasksln1[] PROGMEM="TASKS:";
portTickType xLastWakeTime;
const portTickType xFrequency = 500;
xLastWakeTime=xTaskGetTickCount();
unsigned portBASE_TYPE uxTasks;
vLEDInit1();
LCDinit();
LCDclr();
LCDcursorOFF();
CopyStringtoLCD(welcomeln1, 0, 0);
CopyStringtoLCD(buttonln1, 0, 1);
CopyStringtoLCD(tasksln1, 7, 1);

	for (;;)
	{
		uxTasks=uxTaskGetNumberOfTasks();
		LCDGotoXY(13,1);
		//works only up to 9 tasks
		LCDsendChar(uxTasks+48);
		if (xButtonSemaphore != NULL)
		{
			LCDGotoXY(3,1);
			//poll
			if (xSemaphoreTake(xButtonSemaphore, (portTickType)0)==pdTRUE)
			{
				vLEDToggle1();
				LCDsendChar('1');	
			}
			else
			{
				LCDsendChar('0');	
			}
		}
	vTaskDelayUntil(&xLastWakeTime,xFrequency);	
	}
}