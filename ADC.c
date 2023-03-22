/*******************************************************************/
/*                         INCLUDES                                */
/*******************************************************************/
#include "ADC_reg.h"
#include "lstd.h"
#include "ADC_config.h"
#include "SystemControl.h"
#include "GPIO_config.h"
#include "GPIO.h"
#include "SystemControl.h"

/*******************************************************************/
/*            ARRAY OF POINTERS TO REGISTERS                       */
/*******************************************************************/

u32_t static volatile* ADC_ActiveSampleSequencer_Regs[ADC_Module_Indices]={

      ADC0_ActiveSampleSequencer_Reg,
      ADC1_ActiveSampleSequencer_Reg
};

u32_t static volatile* ADC_EventMultiplexerSelect_Regs[ADC_Module_Indices]={

     ADC0_EventMultiplexerSelect_Reg,
     ADC1_EventMultiplexerSelect_Reg

};

ADCSSMUX_Reg static volatile* ADC_SampleSequenceMUX_Regs[ADC_Module_Indices][SampleSequencer_Indices]={

      {ADC0_SampleSequenceMUX0_Reg,
       ADC0_SampleSequenceMUX1_Reg,
       ADC0_SampleSequenceMUX2_Reg,
       ADC0_SampleSequenceMUX3_Reg
       },

       {ADC1_SampleSequenceMUX0_Reg,
        ADC1_SampleSequenceMUX1_Reg,
        ADC1_SampleSequenceMUX2_Reg,
        ADC1_SampleSequenceMUX3_Reg
       }
};

ADCSSCTL_Reg static volatile* ADC_SampleSequenceCTL_Regs[ADC_Module_Indices][SampleSequencer_Indices]={

       {
        ADC0_SampleSequenceCTL0_Reg,
        ADC0_SampleSequenceCTL1_Reg,
        ADC0_SampleSequenceCTL2_Reg,
        ADC0_SampleSequenceCTL3_Reg
       },

       {
        ADC1_SampleSequenceCTL0_Reg,
        ADC1_SampleSequenceCTL1_Reg,
        ADC1_SampleSequenceCTL2_Reg,
        ADC1_SampleSequenceCTL3_Reg
       }

};


ADCCC_Reg static volatile* ADC_ClockConfiguration_Regs[ADC_Module_Indices]={
   ADC0_ClockConfiguration_Reg,
   ADC1_ClockConfiguration_Reg
};


ADCSSFIFO_Reg static volatile*ADC_SampleSequenceResultFIFO_Regs[SampleSequencer_Indices]={

     ADC_SampleSequenceResultFIFO0_Reg,
     ADC_SampleSequenceResultFIFO1_Reg,
     ADC_SampleSequenceResultFIFO2_Reg,
     ADC_SampleSequenceResultFIFO3_Reg

};


ADCRIS_Reg static volatile*ADC_RawIntStatus_Regs[ADC_Module_Indices]={

      ADC0_RawIntStatus_Reg,
      ADC1_RawIntStatus_Reg
};

ADCISC_Reg static volatile* ADC_IntSatusClear_Regs[ADC_Module_Indices]={
       ADC0_IntSatusClear_Reg,
       ADC1_IntSatusClear_Reg
};


ADCPC_Reg static volatile* ADC_PeripheralConfig_Regs[ADC_Module_Indices]={
         ADC0_PeripheralConfig_Reg,
         ADC1_PeripheralConfig_Reg
};
/*******************************************************************/
/*                   INTERFACE FUNCTIONS                           */
/*******************************************************************/

/**/
void ADC_InitializeModule(ADC_ConfigModule_t* ConfigModule){

/*
    SC_ADC_ClkIntialization(ConfigModule->ConfigADCmoduleNum);

   if (PIOSC == ADC_ClockConfiguration_Regs[ConfigModule->ConfigADCmoduleNum]->bits.ClkSrc){
*/
       /*1-power the pll
        *2-enable the PIOS
        *3-disable the pll*/

/*     SC_Initialization(&ConfigSystemSrc_PLL);
       SC_Initialization(&ConfigSystemSrc_PrecisionInternalOSC);

 }*/

    SC_ADC_ClkIntialization(ConfigModule->ConfigADCmoduleNum);
 }


void ADC_InitializeChannel(GPIO_AdcConfigChannel_t* pt_AdcConfigChannel){

     GPIO_EnableAFSEL_ADC(pt_AdcConfigChannel);
}

void ADC_ConfigureSampleSequencer(ADC_ConfigurationChannel_t* pt_ConfigChannel){

    /*According to tiva c Specifications:
     *Programming of the sample sequencers is allowed without having them
      enabled.
      Therefore, clearing the specific sample sequencer */

    *ADC_ActiveSampleSequencer_Regs[pt_ConfigChannel->ModulesIndexArr] &= ~(1<<(pt_ConfigChannel->SampleSequencerIndexArr));


    *ADC_EventMultiplexerSelect_Regs[pt_ConfigChannel->ModulesIndexArr] &= ~(0xF<<( (pt_ConfigChannel->SampleSequencerIndexArr)*4) );

    *ADC_EventMultiplexerSelect_Regs[pt_ConfigChannel->ModulesIndexArr] |=( (pt_ConfigChannel->ConfigTriggerSource)<<( (pt_ConfigChannel->SampleSequencerIndexArr)*4) );


    ADC_SampleSequenceMUX_Regs[pt_ConfigChannel->ModulesIndexArr][pt_ConfigChannel->SampleSequencerIndexArr]->bits.MUX0= pt_ConfigChannel->ConfigChannel;

    ADC_SampleSequenceCTL_Regs[pt_ConfigChannel->ModulesIndexArr][SampleSequencer_0]->Sample8_EndSequence=1;
    ADC_SampleSequenceCTL_Regs[pt_ConfigChannel->ModulesIndexArr][SampleSequencer_1]->Sample4_EndSequence=1;
    ADC_SampleSequenceCTL_Regs[pt_ConfigChannel->ModulesIndexArr][SampleSequencer_2]->Sample4_EndSequence=1;
    ADC_SampleSequenceCTL_Regs[pt_ConfigChannel->ModulesIndexArr][SampleSequencer_3]->Sample1_EndSequence=1;

    ADC_PeripheralConfig_Regs[pt_ConfigChannel->ModulesIndexArr]->bits.SampleRate=0x7;

    *ADC_ActiveSampleSequencer_Regs[pt_ConfigChannel->ModulesIndexArr] |= (1<<(pt_ConfigChannel->SampleSequencerIndexArr));

}

void ADC_SampleData(ADC_ConfigurationChannel_t* pt_ConfigChannel, u32_t* DataSamplesArr){

    u8_t SamplesNum;

    for(SamplesNum=0; SamplesNum<=(pt_ConfigChannel->Sequencerx_FIFODepth); SamplesNum++){

      while(0 == (ADC_RawIntStatus_Regs[pt_ConfigChannel->ModulesIndexArr]->Register & (1<<pt_ConfigChannel->SampleSequencerIndexArr)) );
      DataSamplesArr[SamplesNum]= ADC_SampleSequenceResultFIFO_Regs[pt_ConfigChannel->SampleSequencerIndexArr]->bits.Data;
      ADC_IntSatusClear_Regs[pt_ConfigChannel->ModulesIndexArr]->Register=(1<<pt_ConfigChannel->SampleSequencerIndexArr);

    }
}
