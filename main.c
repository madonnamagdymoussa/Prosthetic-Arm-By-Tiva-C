/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
#include "SystemControl.h"
#include "GPTM.h"
#include "ServoMotor.h"

int main()
{

    InitializeAllMotors();

    for(; ;){

        CloseHand();

        //GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[0], Frequency_50Hz ,DutyCycle_180DegRotation);

        //DutyCycle_0DegRotation
        //GPTM_GeneratePWM(GPTM_PWMConfig_ArrPtrStruct[0], Frequency_50Hz ,DutyCycle_0DegRotation);

    }


}
