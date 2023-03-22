/*=====================================================================*/
/*                             INCLUDES                                */
/*=====================================================================*/
#include "ADC.h"
#include "ADC_config.h"
#include"EMG_Sensor.h"

void EMGsensor_Initialize(){

     ADC_InitializeModule(EMG_ADCModule_PtrToStruct);
     ADC_InitializeChannel(EMG_GPIOAFSELChannel_PtrToStruct);

 }


void EMGsensor_ReadData(u32_t* SamplesArr){

    ADC_SampleData(EMG_ADCChannel_PtrToStruct, SamplesArr);

}
