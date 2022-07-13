/* =====================================================================================*/
/*                                    INCLUDES                                          */
/* =====================================================================================*/
#include"GPTM_config.h"


GPTM_PWMConfigurationChannel_t GPTM_PWMConfig_32BitTimer0A ={
    _32_64BitTimer_IndiOrConcat,
    TimerA,
    _32_64BitTimerA,
    Timer0,
 };

GPTM_PWMConfigurationChannel_t GPTM_PWMConfig_32BitTimer0B ={
    _32_64BitTimer_IndiOrConcat,
    TimerB,
    _32_64BitTimerB,
    Timer0,
};

GPTM_PWMConfigurationChannel_t GPTM_PWMConfig_32BitTimer1A ={
   _32_64BitTimer_IndiOrConcat,
   TimerA,
   _32_64BitTimerA,
   Timer1,
};

GPTM_PWMConfigurationChannel_t GPTM_PWMConfig_32BitTimer1B ={
    _32_64BitTimer_IndiOrConcat,
    TimerB,
    _32_64BitTimerB,
    Timer1,
 };

GPTM_PWMConfigurationChannel_t GPTM_PWMConfig_32BitTimer2A ={
    _32_64BitTimer_IndiOrConcat,
    TimerA,
    _32_64BitTimerA,
    Timer2,
};

GPTM_PWMConfigurationChannel_t GPTM_PWMConfig_32BitTimer2B ={
    _32_64BitTimer_IndiOrConcat,
    TimerB,
    _32_64BitTimerB,
    Timer2,
};

GPTM_PWMConfigurationChannel_t*  GPTM_PWMConfig_ArrPtrStruct[6]={
    &GPTM_PWMConfig_32BitTimer0A,
    &GPTM_PWMConfig_32BitTimer0B,
    &GPTM_PWMConfig_32BitTimer1A,
    &GPTM_PWMConfig_32BitTimer1B,
    &GPTM_PWMConfig_32BitTimer2A,
    &GPTM_PWMConfig_32BitTimer2B
};
