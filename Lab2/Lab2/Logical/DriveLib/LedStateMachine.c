
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
void LedStateMachine(struct LedStateMachine* inst)
{
	switch(inst->state){
		case ST_UNKNOWN:
			if(inst->timer==10){
				setLeds(inst,!inst->led1,!inst->led1,!inst->led1,!inst->led1);
				inst->timer=0;
			}
			break;
		case ST_CLOSE:
			setLeds(inst,1,1,1,1);
			break;
		case ST_INIT:
		case ST_OPEN:
			setLeds(inst,0,0,0,0);
			break;
		case ST_ACC_POS:
		case ST_DEC_NEG:
			setLeds(inst,1,1,1,0);
			break;
		case ST_POS:
		case ST_NEG:
			setLeds(inst,1,1,0,0);
			break;
		case ST_DEC_POS:
		case ST_ACC_NEG:
			setLeds(inst,1,0,0,0);
			break;
	}
	inst->timer++;
}

void setLeds(struct LedStateMachine* inst, BOOL led1, BOOL led2, BOOL led3, BOOL led4){
	inst->led1 = led1;
	inst->led2 = led2;
	inst->led3 = led3;
	inst->led4 = led4;
}
