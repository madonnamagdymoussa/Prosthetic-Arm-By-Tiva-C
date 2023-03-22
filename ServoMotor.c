
#include "ServoMotor.h"
#include"lstd.h"
#include "PWM.h"


void InitializeAllMotors(void){

    u8_t motorNum =0;

    for( motorNum =0;  motorNum<Fingers; motorNum++){

    //GPTM_InitializePWM(GPTM_PWMConfig_ArrPtrStruct[motorNum], GPIO_GPTMConfigAFSEL_ArrPtrStruct[motorNum]);
    PWM_Initialization(GPIO_PWMConfigAFSEL_ArrPtrStruct[motorNum]);

    }
}

void CloseHand(void){

    int motorNum;

    for( motorNum =0;  motorNum<Fingers; motorNum++){
    PWM_GeneratePWMSignals(PWM_ConfigChannel_ArrPtrStruct[motorNum], DutyCycle_180DegRotation,Frequency_50Hz);
    }
    Delay_ms(250);


    for( motorNum =0;  motorNum<Fingers; motorNum++){
    PWM_GeneratePWMSignals(PWM_ConfigChannel_ArrPtrStruct[motorNum], DutyCycle_90DegRotation,Frequency_50Hz);
    }
    Delay_ms(230);


    for( motorNum =0;  motorNum<Fingers; motorNum++){
    PWM_GeneratePWMSignals(PWM_ConfigChannel_ArrPtrStruct[motorNum], DutyCycle_0DegRotation,Frequency_50Hz);
    }
    Delay_ms(230);


    for( motorNum =0;  motorNum<Fingers; motorNum++){
    PWM_GeneratePWMSignals(PWM_ConfigChannel_ArrPtrStruct[motorNum], DutyCycle_90DegRotation,Frequency_50Hz);
    }
    Delay_ms(250);


}


void OpenHand(void){


    PWM_GeneratePWMSignals(PWM_ConfigChannel_ArrPtrStruct[Thumb], DutyCycle_90DegRotation,Frequency_50Hz);

 }


void Delay_ms(int time_ms)
{
    int i, j;
    for(i = 0 ; i < time_ms; i++)
        for(j = 0; j < 3180; j++)
            {}
}

