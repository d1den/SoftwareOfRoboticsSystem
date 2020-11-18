
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	stateMachine.command = CMD_ENABLE;
	stateMachine.enable = 1;
	ledSM.led1 = ledSM.led2 = ledSM.led3 = ledSM.led4 = 0;
	ledSM.timer = 0;
	doorSM.state = ledSM.state = ST_UNKNOWN;
	doorSM.speed = stateMachine.speed = 0;
}
