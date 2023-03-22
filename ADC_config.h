
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* =====================================================================================*/
/*                                    INCLUDES                                          */
/* =====================================================================================*/
   #include "SystemControl_config.h"
   #include "lstd.h"

/*************************** Madonna Naming Convention in config.h file ***************************/

/* 1-If the enum constants is used for storing the Indices of an Array then the enum name must end with IndexArr_t
 * Example of the enum name: PeripheralName_xxxxIndexArr_t
 *
 * 1.1- If the enum constants is used for storing the Indices of the array the Last constant must store the total
 * number of the indices and that constant name must end with _Indices
 *
 * 2-If the enum constants is used for storing values that will be inserted inside the hardware registers(configurations) then
 * the enum name must begin with Configure keyword
 * Example of the enum name: PeripheralName_Configurexxxxxxx_t
 *
 * 2.1- IF the configuration is related to turning on or off or even controlling a Specific feature
 * then the enum name must end with Mode_t
 * Example of the enum name: PeripheralName_ConfigurexxxxxMode_t
 *
 *
 * 3-If the struct is used to store the information of specific channel such as the channel number
 * and the instance of the typedef enum related to configurations then
 * the name of the struct must end with ConfigurationChannel_t
 * Example of the struct name: PeripheralName_xxxxxConfigurationChannel_t
 *
 *4-The name of the instance created from typedef union must in _unionInst
 *Example of the union name: PeripheralName_xxxxx_unionInst
 *
 * */
/*************************** Madonna Naming Convention in config.h file ***************************/

/* =====================================================================================*/
/*                                    ENUM                                              */
/* =====================================================================================*/
typedef enum{
    SampleSequencer_0,
    SampleSequencer_1,
    SampleSequencer_2,
    SampleSequencer_3,

    SampleSequencer_Indices
}ADC_SampleSequencerIndexArr_t;


typedef enum{
    ADC_Module0,
    ADC_Module1,

    ADC_Module_Indices
}ADC_ModulesIndexArr_t;

typedef enum{

    Processor_Default =0,
    AnalogComparator0 =1,
    AnalogComparator1 =2,
    External_GPIO     =4,
    Timer             =5,
    PWM_Generator0    =6,
    PWM_Generator1    =7,
    PWM_Generator2    =8,
    PWM_Generator3    =9,
    ContinuousSample  =15
}ADC_ConfigTriggerSource_t;

typedef enum{
    AIN0,
    AIN1,
    AIN2,
    AIN3,
    AIN4,
    AIN5,
    AIN6,
    AIN7,
    AIN8,
    AIN9,
    AIN10,
    AIN11
}ADC_ConfigChannel_t;

typedef enum{
    MOSC,
    PIOSC
}ADC_ClkSrc_t;
/* =====================================================================================*/
/*                                    MACROS                                            */
/* =====================================================================================*/
 #define SequencerState_Enabled (1)
 #define SequencerState_Disable (0)

 #define Sequencer0_FIFODepth    (8)
 #define Sequencer1_FIFODepth    (4)
 #define Sequencer2_FIFODepth    (4)
 #define Sequencer3_FIFODepth    (1)


/* =====================================================================================*/
/*                                    STRUCT                                              */
/* =====================================================================================*/
typedef struct{

    ADC_ModulesIndexArr_t ModulesIndexArr;
    ADC_SampleSequencerIndexArr_t SampleSequencerIndexArr;
    ADC_ConfigTriggerSource_t ConfigTriggerSource;
    ADC_ConfigChannel_t ConfigChannel;
    u8_t Sequencerx_FIFODepth;
}ADC_ConfigurationChannel_t;

typedef struct{

        SC_ConfigADCmoduleNum_t  ConfigADCmoduleNum;
        ADC_ClkSrc_t ClkSrc;
}ADC_ConfigModule_t;


extern ADC_ConfigModule_t ADCModule0_Configuration;
extern ADC_ConfigurationChannel_t ADC0_Channel2_Config;


#endif /* ADC_CONFIG_H_ */
