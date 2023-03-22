
#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

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
PWM_Generator0,
PWM_Generator1,
PWM_Generator2,
PWM_Generator3,

PWM_Generator_Indices

}PWM_GeneratorIndexArr_t;

typedef enum{
    PWM_CompareA,
    PWM_CompareB,

    PWM_Comparators_Indices
}PWM_ComparatorsIndexArr_t;

typedef enum{
    PWM_Channel0,
    PWM_Channel1,
    PWM_Channel2,
    PWM_Channel3,
    PWM_Channel4,
    PWM_Channel5,
    PWM_Channel6,
    PWM_Channel7

}PWM_ConfigureChannelNum_t;
/* =====================================================================================*/
/*                                    Typedef Struct                                    */
/* =====================================================================================*/

typedef struct{

    PWM_GeneratorIndexArr_t GeneratorIndexArr;
    PWM_ComparatorsIndexArr_t ComparatorsIndexArr;
    PWM_ConfigureChannelNum_t ConfigureChannelNum;
}PWM_ConfigurationChannel_t;

extern PWM_ConfigurationChannel_t* PWM_ConfigChannel_ArrPtrStruct[8];

#endif /* PWM_CONFIG_H_ */
