
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor.dt = 0.01;
	fb_motor.ke = 7.2;
	fb_motor.Tm = 0.1;
	fb_motor.u = 0;
	fb_motor.phi = 0;
	fb_motor.integrator1.dt = 0.01 / fb_motor.Tm;
	fb_motor.integrator2.dt = 0.01;
	
	fb_motor2.dt = 0.01;
	fb_motor2.ke = 7.2;
	fb_motor2.Tm = 0.1;
	fb_motor2.u = 0;
	fb_motor2.phi = 0;
	fb_motor2.integrator1.dt = 0.01  / fb_motor2.Tm;
	fb_motor2.integrator2.dt = 0.01;
	
	fb_regulator.dt = 0.01;
	fb_regulator.integrator.dt = 0.01;
	fb_regulator.k_i = 7.2;
	fb_regulator.k_p = 0.24 * 3;
	fb_regulator.max_abs_value = 24.0;
	
	speed = 0;
	counter = 0;
}
