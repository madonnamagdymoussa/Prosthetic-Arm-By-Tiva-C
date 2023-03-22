
#ifndef PWM_H_
#define PWM_H_

#include "PWM_config.h"
void PWM_Initialization(GPIO_PWMConfigChannel_t * pt_PWMConfigChannel);
void PWM_GeneratePWMSignals(PWM_ConfigurationChannel_t* pt_ConfigChannel, u8_t PWM_DutyCycle, u8_t PWM_Frequency);


//void Delay_ms(int time_ms);


#endif /* PWM_H_ */
