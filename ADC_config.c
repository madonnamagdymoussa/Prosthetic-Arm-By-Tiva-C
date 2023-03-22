/*============================================================*/
/*                      INCLUDES                              */
/*============================================================*/
#include"ADC_config.h"


ADC_ConfigModule_t ADCModule0_Configuration={
Module0ADC,
 PIOSC
};


ADC_ConfigurationChannel_t ADC0_Channel2_Config={
   ADC_Module0,
   SampleSequencer_0,
   Processor_Default,
   AIN2,
   Sequencer0_FIFODepth,
};



