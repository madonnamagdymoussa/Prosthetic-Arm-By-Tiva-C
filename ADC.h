
#ifndef ADC_H_
#define ADC_H_

#include "ADC_config.h"
#include"GPIO_config.h"
void ADC_InitializeModule(ADC_ConfigModule_t* ConfigModule);
void ADC_InitializeChannel(GPIO_AdcConfigChannel_t* pt_AdcConfigChannel);
void ADC_ConfigureSampleSequencer(ADC_ConfigurationChannel_t* pt_ConfigChannel);
void ADC_SampleData(ADC_ConfigurationChannel_t* pt_ConfigChannel, u32_t* DataSamplesArr);


#endif /* ADC_H_ */
