
#ifndef GPIO_H_
#define GPIO_H_
/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
#include "gpio_config.h"

void GPIO_SetData(GPIO_PortNumIndexArr_t PortNumIndexArr , GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_OutputValue_t OutputValue);

void GPIO_SetPinStatus(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_PinState_t PinState );

void GPIO_TogglePinValue(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum);

void GPIO_ConfigureCommit(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_LockMode_t LockMode);

void GPIO_ConfigureAlternateFunctionSelect(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum , GPIO_AFSELMode_t AFSELMode);

void GPIO_ConfigureAnalogModeSelect(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_AMSELMode_t AMSELMode);

void GPIO_ConfigureDigitalEnable(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_DigitalMode_t DigitalMode);

void GPIO_ConfigurePortControl(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_ConfigureMuxValue_t ConfigureMuxValue );

void GPIO_ConfigureInterruptMask(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum, GPIO_InterruptMaskMode_t InterruptMaskMode);

void GPIO_EXTIClearInterrupt(GPIO_PortNumIndexArr_t PortNumIndexArr, GPIO_ConfigureChannelNum_t ConfigureChannelNum);

void GPIO_TimerPWMInitialization(GPIO_TimerPWMConfigChannel_t * TimerPWMConfigChannel);

void RegisterCallbackFunction(GPIO_PortNumIndexArr_t PortNumIndexArr,CallbackFunc_t pt_callback);

#endif /* GPIO_H_ */



