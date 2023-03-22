#ifndef ADC_REG_H_
#define ADC_REG_H_
/* =====================================================================================*/
/*                                    INCLUDES                                          */
/* =====================================================================================*/
#include "lstd.h"

/* =====================================================================================*/
/*                                    BASE_ADDRESS                                      */
/* =====================================================================================*/
#define ADC0_BASE   (0x40038000)
#define ADC1_BASE   (0x40039000)


/* =====================================================================================*/
/*                                    TYPEDEF UNION                                     */
/* =====================================================================================*/
typedef union{

    struct{
       u32_t MUX0:4;
       u32_t MUX1:4;
       u32_t MUX2:4;
       u32_t MUX3:4;
       u32_t MUX4:4;
       u32_t MUX5:4;
       u32_t MUX6:4;
       u32_t MUX7:4;
    }bits;

    u32_t Register;

}ADCSSMUX_Reg;

typedef union{

  struct{

     u32_t Sample1_DifferentialInputSelect:1;
     u32_t Sample1_EndSequence:1;
     u32_t Sample1_InterruptEnable:1;
     u32_t Sample1_TempSensorSelect:1;

     u32_t Sample2_DifferentialInputSelect:1;
     u32_t Sample2_EndSequence:1;
     u32_t Sample2_InterruptEnable:1;
     u32_t Sample2_TempSensorSelect:1;

     u32_t Sample3_DifferentialInputSelect:1;
     u32_t Sample3_EndSequence:1;
     u32_t Sample3_InterruptEnable:1;
     u32_t Sample3_TempSensorSelect:1;

     u32_t Sample4_DifferentialInputSelect:1;
     u32_t Sample4_EndSequence:1;
     u32_t Sample4_InterruptEnable:1;
     u32_t Sample4_TempSensorSelect:1;

     u32_t Sample5_DifferentialInputSelect:1;
     u32_t Sample5_EndSequence:1;
     u32_t Sample5_InterruptEnable:1;
     u32_t Sample5_TempSensorSelect:1;

     u32_t Sample6_DifferentialInputSelect:1;
     u32_t Sample6_EndSequence:1;
     u32_t Sample6_InterruptEnable:1;
     u32_t Sample6_TempSensorSelect:1;

     u32_t Sample7_DifferentialInputSelect:1;
     u32_t Sample7_EndSequence:1;
     u32_t Sample7_InterruptEnable:1;
     u32_t Sample7_TempSensorSelect:1;

     u32_t Sample8_DifferentialInputSelect:1;
     u32_t Sample8_EndSequence:1;
     u32_t Sample8_InterruptEnable:1;
     u32_t Sample8_TempSensorSelect:1;

  };

  u32_t Register;
}ADCSSCTL_Reg;


typedef union {

    struct{

        u32_t ClkSrc:4;
        u32_t :28;
    }bits;
}ADCCC_Reg;

typedef union{

    struct{

        u32_t Data:12;
        u32_t :20;

    }bits;

    u32_t Register;
}ADCSSFIFO_Reg;


typedef union{

    struct{
     u32_t INR0:1;
     u32_t INR1:1;
     u32_t INR2:1;
     u32_t INR3:1;
     u32_t :12;
     u32_t INRDC:1;
     u32_t :15;
    }bits;

    u32_t Register;

}ADCRIS_Reg;


 typedef union{
     struct{

         u32_t IN0:1;
         u32_t IN1:1;
         u32_t IN2:1;
         u32_t IN3:1;

         u32_t :11;

         u32_t DCINSS0:1;
         u32_t DCINSS1:1;
         u32_t DCINSS2:1;
         u32_t DCINSS3:1;

         u32_t :11;
     }bits;

     u32_t Register;
 }ADCISC_Reg;

 typedef union{
     struct{
         u32_t SampleRate:4;
         u32_t :28;
     }bits;

     u32_t Register;
 }ADCPC_Reg;
/* =====================================================================================*/
/*                                    Register Address                                  */
/* =====================================================================================*/

#define ADC0_ActiveSampleSequencer_Reg       ((u32_t volatile *)(ADC0_BASE +  0x000))
#define ADC1_ActiveSampleSequencer_Reg       ((u32_t volatile *)(ADC1_BASE +  0x000))

#define ADC0_EventMultiplexerSelect_Reg      ((u32_t volatile *)(ADC0_BASE +  0x014))
#define ADC1_EventMultiplexerSelect_Reg      ((u32_t volatile *)(ADC1_BASE +  0x014))


/**/
#define ADC0_SampleSequenceMUX0_Reg           ((ADCSSMUX_Reg volatile *)(ADC0_BASE +  0x040))
#define ADC1_SampleSequenceMUX0_Reg           ((ADCSSMUX_Reg volatile *)(ADC1_BASE +  0x040))

#define ADC0_SampleSequenceMUX1_Reg           ((ADCSSMUX_Reg volatile *)(ADC0_BASE +  0x060))
#define ADC1_SampleSequenceMUX1_Reg           ((ADCSSMUX_Reg volatile *)(ADC1_BASE +  0x060))

#define ADC0_SampleSequenceMUX2_Reg           ((ADCSSMUX_Reg volatile *)(ADC0_BASE +  0x080))
#define ADC1_SampleSequenceMUX2_Reg           ((ADCSSMUX_Reg volatile *)(ADC1_BASE +  0x080))

#define ADC0_SampleSequenceMUX3_Reg           ((ADCSSMUX_Reg volatile *)(ADC0_BASE +  0x0A0))
#define ADC1_SampleSequenceMUX3_Reg           ((ADCSSMUX_Reg volatile *)(ADC1_BASE +  0x0A0))


/**/
#define ADC0_SampleSequenceCTL0_Reg           ((ADCSSCTL_Reg volatile *)(ADC0_BASE +  0x044))
#define ADC1_SampleSequenceCTL0_Reg           ((ADCSSCTL_Reg volatile *)(ADC1_BASE +  0x044))

#define ADC0_SampleSequenceCTL1_Reg           ((ADCSSCTL_Reg volatile *)(ADC0_BASE +  0x064))
#define ADC1_SampleSequenceCTL1_Reg           ((ADCSSCTL_Reg volatile *)(ADC1_BASE +  0x064))

#define ADC0_SampleSequenceCTL2_Reg           ((ADCSSCTL_Reg volatile *)(ADC0_BASE +  0x084))
#define ADC1_SampleSequenceCTL2_Reg           ((ADCSSCTL_Reg volatile *)(ADC1_BASE +  0x084))

#define ADC0_SampleSequenceCTL3_Reg           ((ADCSSCTL_Reg volatile *)(ADC0_BASE +  0x0A4))
#define ADC1_SampleSequenceCTL3_Reg           ((ADCSSCTL_Reg volatile *)(ADC1_BASE +  0x0A4))

#define  ADC0_ClockConfiguration_Reg          ((ADCCC_Reg volatile *)(ADC0_BASE +  0xFC8))
#define  ADC1_ClockConfiguration_Reg          ((ADCCC_Reg volatile *)(ADC1_BASE +  0xFC8))


#define ADC_SampleSequenceResultFIFO0_Reg     ((ADCSSFIFO_Reg volatile*)(ADC0_BASE + 0x048))
#define ADC_SampleSequenceResultFIFO1_Reg     ((ADCSSFIFO_Reg volatile*)(ADC0_BASE + 0x068))
#define ADC_SampleSequenceResultFIFO2_Reg     ((ADCSSFIFO_Reg volatile*)(ADC0_BASE + 0x088))
#define ADC_SampleSequenceResultFIFO3_Reg     ((ADCSSFIFO_Reg volatile*)(ADC0_BASE + 0x0A8))

#define ADC0_RawIntStatus_Reg                 ((ADCRIS_Reg volatile*)(ADC0_BASE + 0x004))
#define ADC1_RawIntStatus_Reg                 ((ADCRIS_Reg volatile*)(ADC1_BASE + 0x004))

#define ADC0_IntSatusClear_Reg                ((ADCISC_Reg volatile*)(ADC0_BASE + 0x00C))
#define ADC1_IntSatusClear_Reg                ((ADCISC_Reg volatile*)(ADC1_BASE + 0x00C))

#define ADC0_PeripheralConfig_Reg             ((ADCPC_Reg volatile*)(ADC0_BASE + 0xFC4))
#define ADC1_PeripheralConfig_Reg             ((ADCPC_Reg volatile*)(ADC1_BASE + 0xFC4))

#endif /* ADC_REG_H_ */
