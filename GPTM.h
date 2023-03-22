
#ifndef GPTM_H_
#define GPTM_H_

#include"GPTM_config.h"
#include "GPIO_config.h"
void GPTM_InitializeDelayMode(GPIO_TimerConfigChannel_t * pt_GPIOTimerConfigChannel, GPTM_ConfigurationChannel_t* pt_TimerConfigChannel);
void GPTM_GeneratePWM(GPTM_ConfigurationChannel_t* ptr_PWMConfigChannel, u32_t PWMFrequency,u8_t DutyCycle);
void GPTM_InitializePWM(GPTM_ConfigurationChannel_t* ptr_PWMConfigChannel, GPIO_TimerConfigChannel_t* pt_PWMConfigAFSEL);

#endif /* GPTM_H_ */
