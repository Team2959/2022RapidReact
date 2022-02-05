
#pragma once

#include <frc/PWM.h>

class Servo
{
public:
    Servo(int channel);
    void SetSpeed(double speed);
private:
    frc::PWM m_pwm;
};
