
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
void DoorStateMachine(struct DoorStateMachine* inst)
{
	switch(inst->state){
		case ST_INIT:
			break;
		case ST_UNKNOWN:
			if(inst->direction){
				inst->speed = -SLOW_SPEED;
				if(inst->sw4){
					setStateAndChangeSpeed(inst,ST_CLOSE);
				}
			}
			else{
				inst->speed = SLOW_SPEED;
				if(inst->sw1){
					setStateAndChangeSpeed(inst,ST_OPEN);
				}
			}
			break;
		case ST_OPEN:
			if(inst->direction){
				setStateAndChangeSpeed(inst,ST_ACC_NEG);
			}
			break;
		case ST_CLOSE:
			if(!inst->direction){
				setStateAndChangeSpeed(inst,ST_ACC_POS);
			}
			break;
		case ST_ACC_POS:
			if(inst->direction){
				setStateAndChangeSpeed(inst,ST_DEC_NEG);
			}
			else if(inst->sw3){
				setStateAndChangeSpeed(inst,ST_POS);
			}
			break;
		case ST_ACC_NEG:
			if(!inst->direction){
				setStateAndChangeSpeed(inst,ST_DEC_POS);
			}
			else if(inst->sw2){
				setStateAndChangeSpeed(inst,ST_NEG);
			}
			break;
		case ST_POS:
			if(inst->direction){
				setStateAndChangeSpeed(inst,ST_NEG);
			}
			else if(inst->sw2){
				setStateAndChangeSpeed(inst,ST_DEC_POS);
			}
			break;
		case ST_NEG:
			if(!inst->direction){
				setStateAndChangeSpeed(inst,ST_POS);
			}
			else if(inst->sw3){
				setStateAndChangeSpeed(inst,ST_DEC_NEG);
			}
			break;
		case ST_DEC_POS:
			if(inst->direction){
				setStateAndChangeSpeed(inst,ST_ACC_NEG);
			}
			else if(inst->sw1){
				setStateAndChangeSpeed(inst,ST_OPEN);
			}
			break;
		case ST_DEC_NEG:
			if(!inst->direction){
				setStateAndChangeSpeed(inst,ST_ACC_POS);
			}
			else if(inst->sw4){
				setStateAndChangeSpeed(inst,ST_CLOSE);
			}
			break;
		default:
			break;
	}
}

void setStateAndChangeSpeed(struct DoorStateMachine* inst, UINT state) {
	inst->state = state;
	switch(state){
		case ST_CLOSE:
			inst->speed = 0;
			break;
		case ST_OPEN:
			inst->speed = 0;
			break;
		case ST_ACC_POS:
			inst->speed = FAST_SPEED;
			break;
		case ST_DEC_POS:
			inst->speed = SLOW_SPEED;
			break;
		case ST_ACC_NEG:
			inst->speed = -FAST_SPEED;
			break;
		case ST_DEC_NEG:
			inst->speed = -SLOW_SPEED;
			break;
		default:
			break;
	}
}
