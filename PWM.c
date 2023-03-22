/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
 #include "PWM_reg.h"
 #include "PWM_config.h"
 #include "lstd.h"
#include "GPIO.h"
#include "SystemControl.h"
#include "NVIC.h"
/* =====================================================================================*/
/*                                  ARRAY OF POINTERS TO REGISTERS                      */
/* =====================================================================================*/
 volatile static PWMCTL_t* PWM_PortControlRegs[PWM_Generator_Indices]={
        PWM0CTL_Reg,
        PWM1CTL_Reg,
        PWM2CTL_Reg,
        PWM3CTL_Reg
 };

volatile static PWMLOAD_t* PWM_LoadRegs[PWM_Generator_Indices]={
        PWM0LOAD_Reg,
        PWM1LOAD_Reg,
        PWM2LOAD_Reg,
        PWM3LOAD_Reg
};

volatile static PWMCMP_t *PWM_CompareRegs[PWM_Comparators_Indices][PWM_Generator_Indices]={

         {PWM0CMPA_Reg,
          PWM1CMPA_Reg,
          PWM2CMPA_Reg,
          PWM3CMPA_Reg
         },

          {
           PWM0CMPB_Reg,
           PWM1CMPB_Reg,
           PWM2CMPB_Reg,
           PWM3CMPB_Reg

          }


};

volatile static PWMGEN_t *PWM_GeneratorControlRegs[PWM_Comparators_Indices][PWM_Generator_Indices]={

           {
            PWM0GENA_Reg,
            PWM1GENA_Reg,
            PWM2GENA_Reg,
            PWM3GENA_Reg
           },

           {
            PWM0GENB_Reg,
            PWM1GENB_Reg,
            PWM2GENB_Reg,
            PWM3GENB_Reg
           }

};

volatile static PWMRIS_t* PWM_RAWInterruptStatus_Regs[PWM_Generator_Indices]={
         PWM0RawInterruptStatus0,
         PWM0RawInterruptStatus1,
         PWM0RawInterruptStatus2,
         PWM0RawInterruptStatus3
};

/* =====================================================================================*/
/*                                  GLOBAL VARIABLES                                    */
/* =====================================================================================*/
   u64_t static PWM_ClkSystemFreq;

/* =====================================================================================*/
/*                                  INTERFACING FUNCTION                                */
/* =====================================================================================*/

 void PWM_Initialization(GPIO_PWMConfigChannel_t * pt_PWMConfigChannel){

     GPIO_EnableAFSEL_PWM(pt_PWMConfigChannel);
     SC_PWMClkIntialization(&PWM_Module0);
     PWM_ClkSystemFreq = SC_GetPWMFrequency(&PWM_Module0);

     /*clear the register before making any changes in the register*/
     //*PWM_PortControlRegs[pt_ConfigChannel->GeneratorIndexArr]->Register=0;

 }

void PWM_GeneratePWMSignals(PWM_ConfigurationChannel_t* pt_ConfigChannel, u8_t PWM_DutyCycle, u8_t PWM_Frequency){

    /*===========================Calculating tick numbers ===============================*/
    u32_t  TotalTickNum;
    u32_t  TimerOnTickNum;

    /*(PWM_Frequency ---> Motor = 50Hz)
     *(PWM_Frequency ---> System = 250,000Hz)
     *
     *TotalTickNum = (250,000Hz) % (50Hz) = 5000 ticks
     *
     *TimerOnTickNum = (5000*(12))%100 = 600 */
    TotalTickNum  =  (PWM_ClkSystemFreq/PWM_Frequency);

    TimerOnTickNum = ( (PWM_DutyCycle*TotalTickNum)/100 );

    /*===========================Calculating tick numbers ===============================*/


    /*Disable any generation of PWM signals before making the changes in the settings */
    (*PWM_PortControlRegs[pt_ConfigChannel->GeneratorIndexArr]).bits.ENABLE=0;

    /*Count Down Mode*/
    (*PWM_PortControlRegs[pt_ConfigChannel->GeneratorIndexArr]).bits.MODE=0;

    (*PWM_GeneratorControlRegs[pt_ConfigChannel->ComparatorsIndexArr][pt_ConfigChannel->GeneratorIndexArr]).bits.ACTLOAD=0x2;
    (*PWM_GeneratorControlRegs[PWM_CompareB ][pt_ConfigChannel->GeneratorIndexArr]).bits.ACTCMPBD=0x3;
    (*PWM_GeneratorControlRegs[PWM_CompareA][pt_ConfigChannel->GeneratorIndexArr]).bits.ACTCMPAD=0x3;


    (*PWM_LoadRegs[pt_ConfigChannel->GeneratorIndexArr]).bits.LOAD=TotalTickNum;
    (*PWM_CompareRegs[pt_ConfigChannel->GeneratorIndexArr][pt_ConfigChannel->ComparatorsIndexArr]).bits.COMP =TimerOnTickNum;

    PWM_InterruptStatusClear->Register |=(1<<(pt_ConfigChannel->GeneratorIndexArr));
   /*Enable the timers*/
   (*PWM_PortControlRegs[pt_ConfigChannel->GeneratorIndexArr]).bits.ENABLE=1;
    PWMENABLE_Reg->PWMChannelsOutputEnable |=(1 << (pt_ConfigChannel->ConfigureChannelNum));

/*
 u32_t IndexCounter;
    for(IndexCounter=0; IndexCounter<TotalTickNum; IndexCounter++){
         while(PWM_RAWInterruptStatus_Regs[pt_ConfigChannel->GeneratorIndexArr]->bits.INTCNTZERO == 0);
         PWM_InterruptStatusClear->Register |=(1<<(pt_ConfigChannel->GeneratorIndexArr));
       }
*/

 }


