
#include <cwtech/Servo.h>

Servo::Servo(int channel)
    : m_pwm(channel)
{
    m_pwm.SetPeriodMultiplier(frc::PWM::PeriodMultiplier::kPeriodMultiplier_4X);
    m_pwm.SetRawBounds(1, 1.5, 1.5, 1.5, 2);
}

void Servo::SetSpeed(double speed)
{
    m_pwm.SetSpeed(speed);
}
