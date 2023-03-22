/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
  #include "GPIO_config.h"

/* =====================================================================================*/
/*                                   INSTANCE OF STRUCT                                 */
/* =====================================================================================*/

/*==================================================*/
/*     Config for  AFSEL_PWM                        */
/*==================================================*/
GPIO_TimerConfigChannel_t Timer0A_32_64Bit ={
     PortC,
     Channel_4,
     PWM_32_64BitTimer0A_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer0B_32_64Bit={
     PortC,
     Channel_5,
     PWM_32_64BitTimer0B_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer1A_32_64Bit={
     PortC,
     Channel_6,
     PWM_32_64BitTimer1A_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer1B_32_64Bit={
    PortC,
    Channel_7,
    PWM_32_64BitTimer1B_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer2A_32_64Bit={
   PortD,
   Channel_0,
  PWM_32_64BitTimer2A_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer2B_32_64Bit={
   PortD,
   Channel_1,
   PWM_32_64BitTimer2B_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer3A_32_64Bit={
   PortD,
   Channel_2,
   PWM_32_64BitTimer3A_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer3B_32_64Bit={
   PortD,
   Channel_3,
   PWM_32_64BitTimer3B_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer4A_32_64Bit={
   PortD,
   Channel_4,
   PWM_32_64BitTimer4A_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer4B_32_64Bit={
  PortD,
  Channel_5,
  PWM_32_64BitTimer4B_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer5A_32_64Bit ={
   PortD,
   Channel_6,
   PWM_32_64BitTimer5A_IndexArr
};/*************************************************/

GPIO_TimerConfigChannel_t Timer5B_32_64Bit={
   PortD,
   Channel_7,
   PWM_32_64BitTimer5B_IndexArr
};/*************************************************/



/*============================= PWM Module=======================================*/
GPIO_PWMConfigChannel_t Module0_PWM0_Generator0={
   PortB,
   Channel_6

};

GPIO_PWMConfigChannel_t Module0_PWM1_Generator0={
   PortB,
   Channel_7

};

GPIO_PWMConfigChannel_t Module0_PWM0_Generator1={
   PortB,
   Channel_4

};

GPIO_PWMConfigChannel_t Module0_PWM1_Generator1={
   PortB,
   Channel_5

};

GPIO_PWMConfigChannel_t Module0_PWM0_Generator2={
   PortE,
   Channel_4

};

GPIO_PWMConfigChannel_t Module0_PWM1_Generator2={
   PortE,
   Channel_5

};

GPIO_PWMConfigChannel_t Module0_PWM0_Generator3={
     PortD,
     Channel_0

};

GPIO_PWMConfigChannel_t Module0_PWM1_Generator3={
    PortD,
    Channel_1

};


/*============================= ADC Module=======================================*/
GPIO_AdcConfigChannel_t ADC_Channel0={
   PortE,
   Channel_3
};

GPIO_AdcConfigChannel_t ADC_Channel1={
   PortE,
   Channel_2
};


GPIO_AdcConfigChannel_t ADC_Channel2={
   PortE,
   Channel_1
};


GPIO_AdcConfigChannel_t ADC_Channel3={
   PortE,
   Channel_0
};


GPIO_AdcConfigChannel_t ADC_Channel4={
   PortD,
   Channel_3
};

GPIO_AdcConfigChannel_t ADC_Channel5={
   PortD,
   Channel_2
};


GPIO_AdcConfigChannel_t ADC_Channel6={
   PortD,
   Channel_1
};

GPIO_AdcConfigChannel_t ADC_Channel7={
   PortD,
   Channel_0
};

GPIO_AdcConfigChannel_t ADC_Channel8={
   PortE,
   Channel_5
};

GPIO_AdcConfigChannel_t ADC_Channel9={
   PortE,
   Channel_4
};

GPIO_AdcConfigChannel_t ADC_Channel10={
   PortB,
   Channel_4
};

GPIO_AdcConfigChannel_t ADC_Channel11={
   PortB,
   Channel_5
};

/* =====================================================================================*/
/*                         ARRAY OF POINTERS TO STRUCT                                  */
/* =====================================================================================*/

GPIO_TimerConfigChannel_t * const GPIO_TimerAFSELConfig_ArrPtrStruct[12]={
      &Timer0A_32_64Bit,
      &Timer0B_32_64Bit,
      &Timer1A_32_64Bit,
      &Timer1B_32_64Bit,
      &Timer2A_32_64Bit,
      &Timer2B_32_64Bit,
      &Timer3A_32_64Bit,
      &Timer3B_32_64Bit,
      &Timer4A_32_64Bit,
      &Timer4B_32_64Bit,
      &Timer5A_32_64Bit,
      &Timer5B_32_64Bit,
};

GPIO_PWMConfigChannel_t * const GPIO_PWMConfigAFSEL_ArrPtrStruct[8]={
     &Module0_PWM0_Generator0,
     &Module0_PWM1_Generator0,
     &Module0_PWM0_Generator1,
     &Module0_PWM1_Generator1,
     &Module0_PWM0_Generator2,
     &Module0_PWM1_Generator2,
     &Module0_PWM0_Generator3,
     &Module0_PWM1_Generator3

};


GPIO_AdcConfigChannel_t* const GPIO_AdcConfigAFSEL_ArrPtrStruct[11]={

      &ADC_Channel0,
      &ADC_Channel1,
      &ADC_Channel2,
      &ADC_Channel3,
      &ADC_Channel4,
      &ADC_Channel5,
      &ADC_Channel6,
      &ADC_Channel7,
      &ADC_Channel8,
      &ADC_Channel9,
      &ADC_Channel10,
      &ADC_Channel11
};
