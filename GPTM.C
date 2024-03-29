/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/

#include "GPTM_reg.h"
#include"lstd.h"
#include "GPTM_config.h"
#include "SystemControl.h"
#include "GPIO.h"

/* =====================================================================================*/
/*                                  ARRAY OF POINTERS TO REGISTERS                      */
/* =====================================================================================*/

/**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/

/*we cast that array --> void because we can use it as 16Bit timer if it is NOT in the concatenated mode
 * Or we can use it as 32Bit timer if it is in the concatenated mode
 * So there is no need to waste memory and create 2 arrays
 * only create one void pointer and re-use it
 *
 * NOTE: that is done with timer A registers only there is no need to to that with timer B registers */
volatile static void* const GPTM_16_32_BitTimerA_IntervalLoad[TimerChannel_Indices]={
      (void*)GPTM_16_32BitTimer0AIntervalLoad,
      (void*)GPTM_16_32BitTimer1AIntervalLoad,
      (void*)GPTM_16_32BitTimer2AIntervalLoad,
      (void*)GPTM_16_32BitTimer3AIntervalLoad,
      (void*)GPTM_16_32BitTimer4AIntervalLoad,
      (void*)GPTM_16_32BitTimer5AIntervalLoad
};


/*we cast that array --> void because we can use it as 32Bit timer if it is NOT in the concatenated mode
 * Or we can use it as 64Bit timer if it is in the concatenated mode
 * So there is no need to waste memory and create 2 arrays
 * only create one void pointer and re-use it by casting
 *
 * NOTE:that is done with timer A registers only there is no need to to that with timer B registers*/
volatile static void* const GPTM_32_64_BitTimerA_IntervalLoad[TimerChannel_Indices]={
       (void*)GPTM_32_64BitTimer0AIntervalLoad,
       (void*)GPTM_32_64BitTimer1AIntervalLoad,
       (void*)GPTM_32_64BitTimer2AIntervalLoad,
       (void*)GPTM_32_64BitTimer3AIntervalLoad,
       (void*)GPTM_32_64BitTimer4AIntervalLoad,
       (void*)GPTM_32_64BitTimer5AIntervalLoad
};


volatile static u16_t* const GPTM_16BitTimerB_IntervalLoad[TimerChannel_Indices]={
      (u16_t*)GPTM_16BitTimer0BIntervalLoad,
      (u16_t*)GPTM_16BitTimer1BIntervalLoad,
      (u16_t*)GPTM_16BitTimer2BIntervalLoad,
      (u16_t*)GPTM_16BitTimer3BIntervalLoad,
      (u16_t*)GPTM_16BitTimer4BIntervalLoad,
      (u16_t*)GPTM_16BitTimer5BIntervalLoad
};

volatile static u32_t* const GPTM_32BitTimerB_IntervalLoad[TimerChannel_Indices]={

     (u32_t*)GPTM_32BitTimer0BIntervalLoad,
     (u32_t*)GPTM_32BitTimer1BIntervalLoad,
     (u32_t*)GPTM_32BitTimer2BIntervalLoad,
     (u32_t*)GPTM_32BitTimer3BIntervalLoad,
     (u32_t*)GPTM_32BitTimer4BIntervalLoad,
     (u32_t*)GPTM_32BitTimer5BIntervalLoad,

};


/*we cast that array --> void because we can use it as 16Bit timer if it is NOT in the concatenated mode
 * Or we can use it as 32Bit timer if it is in the concatenated mode
 * So there is no need to waste memory and create 2 arrays
 * only create one void pointer and re-use it
 *
 * NOTE: that is done with timer A registers only there is no need to to that with timer B registers */
volatile static void* const GPTM_32_64_BitTimerA_Match[TimerChannel_Indices]={
       (void*)GPTM_32_64BitTimer0AMatch,
       (void*)GPTM_32_64BitTimer1AMatch,
       (void*)GPTM_32_64BitTimer2AMatch,
       (void*)GPTM_32_64BitTimer3AMatch,
       (void*)GPTM_32_64BitTimer4AMatch,
       (void*)GPTM_32_64BitTimer5AMatch
};

volatile static u32_t* const GPTM_32BitTimerB_Match[TimerChannel_Indices]={

     (u32_t*)GPTM_32_64BitTimer0BMatch,
     (u32_t*)GPTM_32_64BitTimer0BMatch,
     (u32_t*)GPTM_32_64BitTimer0BMatch,
     (u32_t*)GPTM_32_64BitTimer0BMatch,
     (u32_t*)GPTM_32_64BitTimer0BMatch,
     (u32_t*)GPTM_32_64BitTimer0BMatch,

};

//create 2d array
volatile static GPTMTMR_Reg* const GPTM_TimerMode[TimerSizeName_Indices][TimerChannel_Indices]={

   { (GPTMTMR_Reg*)GPTM_16_32BitTimer0AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer1AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer2AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer3AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer4AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer5AMode
   },

   { (GPTMTMR_Reg*)GPTM_32_64BitTimer0AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer1AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer2AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer3AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer4AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer5AMode
   },

{   (GPTMTMR_Reg*)GPTM_16_32BitTimer0BMode,
    (GPTMTMR_Reg*)GPTM_16_32BitTimer1BMode,
    (GPTMTMR_Reg*)GPTM_16_32BitTimer2BMode,
    (GPTMTMR_Reg*)GPTM_16_32BitTimer3BMode,
    (GPTMTMR_Reg*)GPTM_16_32BitTimer4BMode,
    (GPTMTMR_Reg*)GPTM_16_32BitTimer5BMode
 },

 {  (GPTMTMR_Reg*)GPTM_32_64BitTimer0BMode,
    (GPTMTMR_Reg*)GPTM_32_64BitTimer1BMode,
    (GPTMTMR_Reg*)GPTM_32_64BitTimer2BMode,
    (GPTMTMR_Reg*)GPTM_32_64BitTimer3BMode,
    (GPTMTMR_Reg*)GPTM_32_64BitTimer4BMode,
    (GPTMTMR_Reg*)GPTM_32_64BitTimer5BMode
 }

};


volatile static GPTMCTL_reg* const GPTM_Control[TimerSize_Indices][TimerChannel_Indices]={

  {
   (GPTMCTL_reg*)GPTM_16_32BitTimer0Control,
   (GPTMCTL_reg*)GPTM_16_32BitTimer1Control,
   (GPTMCTL_reg*)GPTM_16_32BitTimer2Control,
   (GPTMCTL_reg*)GPTM_16_32BitTimer3Control,
   (GPTMCTL_reg*)GPTM_16_32BitTimer4Control,
   (GPTMCTL_reg*)GPTM_16_32BitTimer5Control

  },

  {
   (GPTMCTL_reg*)GPTM_32_64BitTimer0Control,
   (GPTMCTL_reg*)GPTM_32_64BitTimer1Control,
   (GPTMCTL_reg*)GPTM_32_64BitTimer2Control,
   (GPTMCTL_reg*)GPTM_32_64BitTimer3Control,
   (GPTMCTL_reg*)GPTM_32_64BitTimer4Control,
   (GPTMCTL_reg*)GPTM_32_64BitTimer5Control
  }

};


volatile static GPTMCFG_Reg* const GPTM_ConfigurationRegisters[TimerSize_Indices][TimerChannel_Indices]={
     {
      (GPTMCFG_Reg *)GPTM_16_32BitTimer0Configuration,
      (GPTMCFG_Reg *)GPTM_16_32BitTimer1Configuration,
      (GPTMCFG_Reg *)GPTM_16_32BitTimer2Configuration,
      (GPTMCFG_Reg *)GPTM_16_32BitTimer3Configuration,
      (GPTMCFG_Reg *)GPTM_16_32BitTimer4Configuration,
      (GPTMCFG_Reg *)GPTM_16_32BitTimer5Configuration

      },

      {
       (GPTMCFG_Reg *)GPTM_32_64BitTimer0Configuration,
       (GPTMCFG_Reg *)GPTM_32_64BitTimer1Configuration,
       (GPTMCFG_Reg *)GPTM_32_64BitTimer2Configuration,
       (GPTMCFG_Reg *)GPTM_32_64BitTimer3Configuration,
       (GPTMCFG_Reg *)GPTM_32_64BitTimer4Configuration,
       (GPTMCFG_Reg *)GPTM_32_64BitTimer5Configuration,
      }
};

/* =====================================================================================*/
/*                                  STATIC INLINE FUNCTION                              */
/* =====================================================================================*/
/*The function is INLINE because: The function is short so there is no need to make context switching
 * and waist the overhead time
 *
 * The function is static because: we don't need to make direct connection between layers because inline function
 * is a text replacement plus it's not preferable to
 *   */
static inline void GPTM_EnableClkTimer(GPTM_ChannelIndexArr_t GPTM_ChannelIndexArr_t, GPTM_TimerSizeIndexArr_t TimerSizeIndexArr){

    if( _16_32BitTimer_IndiOrConcat == TimerSizeIndexArr){
    SC_RCGCTIMER_Reg |=(1<<GPTM_ChannelIndexArr_t);
    }

    else if( _32_64BitTimer_IndiOrConcat == TimerSizeIndexArr){
        SC_RCGCWTIMER_Reg |=(1<<GPTM_ChannelIndexArr_t);
    }
}

void static inline GPTM_EnableTimer(GPTM_ConfigureTimerName_t ConfigureTimerName, GPTM_ChannelIndexArr_t GPTM_ChannelIndexArr_t , GPTM_TimerSizeIndexArr_t TimerSizeIndexArr){

   (*GPTM_Control[TimerSizeIndexArr][GPTM_ChannelIndexArr_t]).Register |=(1<< ConfigureTimerName);
 }

void static inline GPTM_DisableTimer(GPTM_ConfigureTimerName_t ConfigureTimerName, GPTM_ChannelIndexArr_t GPTM_ChannelIndexArr_t , GPTM_TimerSizeIndexArr_t TimerSizeIndexArr){

   (*GPTM_Control[TimerSizeIndexArr][GPTM_ChannelIndexArr_t]).Register &= ~(1<< ConfigureTimerName);

}
/************************************* STATIC INLINE Function *************************************************************/



/* =====================================================================================*/
/*                                  INTERFACE FUNCTION                              */
/* =====================================================================================*/

void GPTM_InitializePWM(GPTM_PWMConfigurationChannel_t* ptr_PWMConfigChannel, GPIO_TimerPWMConfigChannel_t* pt_PWMConfigAFSEL){

    GPIO_TimerPWMInitialization(pt_PWMConfigAFSEL);

    GPTM_EnableClkTimer(ptr_PWMConfigChannel->ChannelIndexArr, ptr_PWMConfigChannel->TimerSizeIndexArr);
   /****************************** STEP1 ******************************/
    /*Disable the timer*/
    GPTM_DisableTimer(ptr_PWMConfigChannel->ConfigureTimerName, ptr_PWMConfigChannel->ChannelIndexArr , ptr_PWMConfigChannel->TimerSizeIndexArr);

     /****************************** STEP2 ******************************/
    (*GPTM_ConfigurationRegisters[ptr_PWMConfigChannel->TimerSizeIndexArr][ptr_PWMConfigChannel->ChannelIndexArr]).bits.Configuration = 0x4;

    /****************************** STEP3 ******************************/
    (*GPTM_TimerMode[ptr_PWMConfigChannel->TimerSizeNameIndexArr][ptr_PWMConfigChannel->ChannelIndexArr]).bits.TimerAlternateModeSelect=1;
    (*GPTM_TimerMode[ptr_PWMConfigChannel->TimerSizeNameIndexArr][ptr_PWMConfigChannel->ChannelIndexArr]).bits.TimerMode =PeriodicMode;
    (*GPTM_TimerMode[ptr_PWMConfigChannel->TimerSizeNameIndexArr][ptr_PWMConfigChannel->ChannelIndexArr]).bits.TimerCaptureMode =CaptureMode_EdgeCountMode;

    /****************************** STEP4 ******************************/
    (*GPTM_Control[ptr_PWMConfigChannel->TimerSizeIndexArr][ptr_PWMConfigChannel->ChannelIndexArr]).bits.TimerA_PWMOutputLevel=PWM_OutputNotInverted;
    (*GPTM_Control[ptr_PWMConfigChannel->TimerSizeIndexArr][ptr_PWMConfigChannel->ChannelIndexArr]).bits.TimerB_PWMOutputLevel=PWM_OutputNotInverted;

}

void GPTM_GeneratePWM(GPTM_PWMConfigurationChannel_t* ptr_PWMConfigChannel, u32_t PWMFrequency,u8_t DutyCycle){

 //GPTM_PWM_Disable(ptr_PWMConfigChannel);

 u64_t SystemClkFreq;
 u32_t TotalTickNum;
 u32_t TimerOnTickNum;

 SystemClkFreq = SC_GetSystemClock();
 TotalTickNum   =  (SystemClkFreq/PWMFrequency);
 TimerOnTickNum = ( (DutyCycle*TotalTickNum)/100 );

 if( TimerA == ptr_PWMConfigChannel->ConfigureTimerName){

    *( (u32_t*)GPTM_32_64_BitTimerA_IntervalLoad[ptr_PWMConfigChannel->ChannelIndexArr])=TotalTickNum;
    *( (u32_t *)GPTM_32_64_BitTimerA_Match[ptr_PWMConfigChannel->ChannelIndexArr])=TimerOnTickNum;
 }

 else if (TimerB == ptr_PWMConfigChannel->ConfigureTimerName){
     *GPTM_32BitTimerB_IntervalLoad[ptr_PWMConfigChannel->ChannelIndexArr]=TotalTickNum;
     *GPTM_32BitTimerB_Match[ptr_PWMConfigChannel->ChannelIndexArr]=TimerOnTickNum;
 }

 GPTM_EnableTimer(ptr_PWMConfigChannel->ConfigureTimerName, ptr_PWMConfigChannel->ChannelIndexArr , ptr_PWMConfigChannel->TimerSizeIndexArr);
}

