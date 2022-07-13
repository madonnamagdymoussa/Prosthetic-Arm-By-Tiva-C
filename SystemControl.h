
#ifndef SYSTEMCONTROL_H_
#define SYSTEMCONTROL_H_

#include "lstd.h"
#include "SystemControl_config.h"

#define PRECISION_INTERNAL_OSC               (16000000)
#define LOW_FREQUENCY_INTERNAL_OSC           (30000)
#define PRECISION_INTERNAL_OSC_DIV4          (4000000)
#define HIBERNATION_OSC                      (32768)
#define MAIN_OSC                             (5000000)


u32_t SC_GetSystemClock(void);
u32_t SC_GetOscillatorValue(void);
void SC_Initialization(SystemControlConfig_t* ptConfig);
//void SC_PWMClkIntialization(SC_PWMConfiguration_t* PWMConfiguration);

//int SC_PWMSetFrequency(u32_t PWMFreq,SC_PWMConfiguration_t * pt_PWMConfiguration);

#endif /* SYSTEMCONTROL_H_ */
