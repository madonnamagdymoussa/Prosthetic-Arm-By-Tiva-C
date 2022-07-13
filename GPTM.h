
#ifndef GPTM_H_
#define GPTM_H_

#include"GPTM_config.h"

void GPTM_GeneratePWM(GPTM_PWMConfigurationChannel_t* ptr_PWMConfigChannel, u32_t PWMFrequency,u8_t DutyCycle);

void GPTM_ConfigureAlternateFunction(GPTM_PWMConfigurationChannel_t* ptr_PWMConfigChannel);
void GPTM_InitializePWM(GPTM_PWMConfigurationChannel_t* ptr_PWMConfigChannel, GPIO_TimerPWMConfigChannel_t* pt_PWMConfigAFSEL);

#endif /* GPTM_H_ */
