
#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "GPTM.h"

typedef enum{
    Thumb,
    Index,
    Middle,
    Ring,
    Pinky,
    Fingers
}FingerMotor_IndexArr_t;

typedef enum{
DutyCycle_180DegRotation =12,
DutyCycle_90DegRotation =7,
DutyCycle_0DegRotation = 2
}ServoMotor_Duty_t;

#define Frequency_50Hz  (50)
// 1/50 --> 20 ms

void InitializeAllMotors(void);

void CloseHand(void);

void OpenHand(void);

void Delay_ms(int time_ms);

#endif /* SERVOMOTOR_H_ */
