
#ifndef EMG_SENSOR_H_
#define EMG_SENSOR_H_

#include "GPIO_config.h"
#define EMG_GPIOAFSELChannel_PtrToStruct  GPIO_AdcConfigAFSEL_ArrPtrStruct[2]
#define EMG_ADCModule_PtrToStruct         &ADCModule0_Configuration
#define EMG_ADCChannel_PtrToStruct        &ADC0_Channel2_Config



void EMGsensor_Initialize();
void EMGsensor_ReadData(u32_t* SamplesArr);

#endif /* EMG_SENSOR_H_ */
