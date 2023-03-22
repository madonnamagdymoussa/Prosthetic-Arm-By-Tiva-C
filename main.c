/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
#include "SystemControl.h"
#include "GPTM.h"
#include "ServoMotor.h"
#include "EMG_Sensor.h"

int main()
{

 //   u32_t EMG_DataSamplesArr1[8];
//    u32_t EMG_DataSamplesArr2[8];
    InitializeAllMotors();

   // EMGsensor_Initialize();



for(; ;){

    CloseHand();
    //OpenHand();

    //EMGsensor_ReadData(EMG_DataSamplesArr1);
    //EMGsensor_ReadData(EMG_DataSamplesArr2);

}


}
