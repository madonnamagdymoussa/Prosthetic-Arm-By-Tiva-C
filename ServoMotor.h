
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
DutyCycle_180DegRotation = 10,
DutyCycle_90DegRotation = 8,
DutyCycle_0DegRotation = 3
}ServoMotor_Duty_t;

#define Frequency_50Hz  (50)

void InitializeAllMotors(void);

void CloseHand(void);

#endif /* SERVOMOTOR_H_ */
