
#include "ServoMotor.h"
#include"lstd.h"

void InitializeAllMotors(void){

    u8_t motorNum =0;

    for( motorNum =0;  motorNum<Fingers; motorNum++){

    GPTM_InitializePWM(GPTM_PWMConfig_ArrPtrStruct[motorNum], GPIO_PWMConfigAFSEL_ArrPtrStruct[motorNum]);

    }
}

void CloseHand(void){

    GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[Thumb], Frequency_50Hz,DutyCycle_180DegRotation);
    GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[Index], Frequency_50Hz,DutyCycle_180DegRotation);
    GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[Middle], Frequency_50Hz,DutyCycle_180DegRotation);
    GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[Ring], Frequency_50Hz,DutyCycle_180DegRotation);
    GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[Pinky], Frequency_50Hz,DutyCycle_180DegRotation);

}

/*
void OpenHand(){

    GPTM_GeneratePWM(ArrPtrStruct[Thumb], 50,2);
    GPTM_GeneratePWM(ArrPtrStruct[Index], 50,2);
    GPTM_GeneratePWM(ArrPtrStruct[Middle], 50,2);
    GPTM_GeneratePWM(ArrPtrStruct[Ring], 50,2);
    GPTM_GeneratePWM(ArrPtrStruct[Pinky], 50,2);

}

*/
