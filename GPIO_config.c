/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
  #include "GPIO_config.h"

/* =====================================================================================*/
/*                                   INSTANCE OF STRUCT                                 */
/* =====================================================================================*/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer0A ={
     PortC,
     Channel_4,
     PWM_32_64BitTimer0A_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer0B={
     PortC,
     Channel_5,
     PWM_32_64BitTimer0B_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer1A={
     PortC,
     Channel_6,
     PWM_32_64BitTimer1A_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer1B={
    PortC,
    Channel_7,
    PWM_32_64BitTimer1B_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer2A={
   PortD,
   Channel_0,
  PWM_32_64BitTimer2A_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer2B={
   PortD,
   Channel_1,
   PWM_32_64BitTimer2B_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer3A={
   PortD,
   Channel_2,
   PWM_32_64BitTimer3A_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer3B={
   PortD,
   Channel_3,
   PWM_32_64BitTimer3B_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer4A={
   PortD,
   Channel_4,
   PWM_32_64BitTimer4A_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer4B={
  PortD,
  Channel_5,
  PWM_32_64BitTimer4B_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer5A={
   PortD,
   Channel_6,
   PWM_32_64BitTimer5A_IndexArr
};/*************************************************/

GPIO_TimerPWMConfigChannel_t PWM_32_64BitTimer5B={
   PortD,
   Channel_7,
   PWM_32_64BitTimer5B_IndexArr
};/*************************************************/

/* =====================================================================================*/
/*                         ARRAY OF POINTERS TO STRUCT                                  */
/* =====================================================================================*/

GPIO_TimerPWMConfigChannel_t * const GPIO_PWMConfigAFSEL_ArrPtrStruct[12]={
      &PWM_32_64BitTimer0A,
      &PWM_32_64BitTimer0B,
      &PWM_32_64BitTimer1A,
      &PWM_32_64BitTimer1B,
      &PWM_32_64BitTimer2A,
      &PWM_32_64BitTimer2B,
      &PWM_32_64BitTimer3A,
      &PWM_32_64BitTimer3B,
      &PWM_32_64BitTimer4A,
      &PWM_32_64BitTimer4B,
      &PWM_32_64BitTimer5A,
      &PWM_32_64BitTimer5B,
};

