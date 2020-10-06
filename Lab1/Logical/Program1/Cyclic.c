
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if (enable) 
	{
		if (counter == 200) 
		{
			speed = 0;
		}
		else if (counter == 50) 
		{
			speed = 50;
		}
		if (counter < 201)
			counter++;
		
		fb_regulator.e = speed-fb_motor.w;
		FB_Regulator(&fb_regulator);
		fb_motor.u = fb_regulator.u;
		fb_motor2.u = speed * fb_motor2.ke;
		FB_Motor(&fb_motor);
		FB_Motor(&fb_motor2);
	}	
}
