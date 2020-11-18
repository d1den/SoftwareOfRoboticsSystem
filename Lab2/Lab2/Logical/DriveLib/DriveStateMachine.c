
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DriveStateMachine(struct DriveStateMachine* inst)
{
	if(inst->enable) {
		UINT stateMask = inst->state & 0x6f;
		switch (stateMask) {
			case ST_READY:
				inst->command = CMD_ENABLE;
				break;
			case ST_DISABLED:
				inst->command = CMD_SHUTDOWN;
				break;
			case ST_SWITCHED_ON:
				inst->command = CMD_SWITCH_ON;
		}
	}
	else
		inst->command = CMD_SHUTDOWN;
}
