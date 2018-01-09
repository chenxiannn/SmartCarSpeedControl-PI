#include "EIT_SpeedL.h"
PID MotorL_PID;
void MotorLPID_Init(void)
{
    MotorLPID_InitParam();
    MotorLPID_InitState(0);
    MotorLPID_SetSpeed( 0);
    PID_InitFbVal(&MotorL_PID,0);
}
void MotorLPID_InitParam(void)
{
	MotorL_PID.Kp = gParam.MotorL_PID_KP;
        MotorL_PID.Ki = gParam.MotorL_PID_KI*gParam.MotorL_PID_Ts;
	MotorL_PID.Kd = -gParam.MotorL_PID_KD/gParam.MotorL_PID_Ts;
	MotorL_PID.MAX_Val = MOTORL_PWM_MAX;
	MotorL_PID.MIN_Val = MOTORL_PWM_MIN;	
}
void MotorLPID_InitState(int32 I)
{
	MotorL_PID.I = I;
}
void MotorLPID_SetSpeed( int32 spSpeed)
{
	MotorL_PID.spVal = spSpeed;
}
void MotorLPID_SpeedControl(void)
{
	
    PID_Run_PID(&MotorL_PID);
    MotorL_Run(MotorL_PID.outVal);
}

