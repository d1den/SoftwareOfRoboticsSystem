
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
	/*TODO: Add your code here*/
	REAL a = inst->e * inst->k_p;
	REAL b = inst->e * inst->k_i; //inst->dt
	a = a > inst->max_abs_value ? inst->max_abs_value : a;
	a = a < -inst->max_abs_value ? -inst->max_abs_value : a;
	inst->integrator.in = b + inst->iyOld;
	FB_Integrator(&inst->integrator);
	REAL sum = a + inst->integrator.out;
	inst->u = sum;
	inst->u = inst->u > inst->max_abs_value ? inst->max_abs_value : inst->u;
	inst->u = inst->u < -inst->max_abs_value ? -inst->max_abs_value : inst->u;
	inst->iyOld = inst->u - sum;
}
