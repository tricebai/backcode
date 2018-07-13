#include "door.h"
#include <board.h>
#include <rtthread.h>

void appmain(void)
{
	DOOR_HW_Init();
	
	while(1)
	{
			DOOR_Set(1);

			rt_thread_delay(10);
			DOOR_Set(0);
			rt_thread_delay(10);
	}
}
