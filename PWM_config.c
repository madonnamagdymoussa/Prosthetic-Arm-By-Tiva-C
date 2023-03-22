
/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
#include "PWM_config.h"

/* =====================================================================================*/
/*                                   INSTANCE OF STRUCT                                 */
/* =====================================================================================*/

PWM_ConfigurationChannel_t  PWMChannel0_Module0={
      PWM_Generator0,
      PWM_CompareA,
      PWM_Channel0
};

PWM_ConfigurationChannel_t  PWMChannel1_Module0={
      PWM_Generator0,
      PWM_CompareB,
      PWM_Channel1
};

PWM_ConfigurationChannel_t  PWMChannel2_Module0={
      PWM_Generator0,
      PWM_CompareA,
      PWM_Channel2
};

PWM_ConfigurationChannel_t  PWMChannel3_Module0={
      PWM_Generator0,
      PWM_CompareB,
      PWM_Channel3
};

PWM_ConfigurationChannel_t  PWMChannel4_Module0={
      PWM_Generator0,
      PWM_CompareA,
      PWM_Channel4
};

PWM_ConfigurationChannel_t  PWMChannel5_Module0={
      PWM_Generator0,
      PWM_CompareB,
      PWM_Channel5
};

PWM_ConfigurationChannel_t  PWMChannel6_Module0={
      PWM_Generator0,
      PWM_CompareA,
      PWM_Channel6
};

PWM_ConfigurationChannel_t  PWMChannel7_Module0={
      PWM_Generator0,
      PWM_CompareB,
      PWM_Channel7
};

/* =====================================================================================*/
/*                                   ARRAY OF POINTERS TO STRUCT                        */
/* =====================================================================================*/

 PWM_ConfigurationChannel_t* PWM_ConfigChannel_ArrPtrStruct[8]={

      &PWMChannel0_Module0,
      &PWMChannel1_Module0,
      &PWMChannel2_Module0,
      &PWMChannel3_Module0,
      &PWMChannel4_Module0,
      &PWMChannel5_Module0,
      &PWMChannel6_Module0,
      &PWMChannel7_Module0

 };
