#include <subsystems/Intake.h>

Intake::Intake(cwtech::Debug* parent)
    : cwtech::Debug("Intake", parent)
{
}

void Intake::ToggleIntake() 
{
    if (m_arms.Get() == true) 
    {
        m_arms.Set(false);
        m_motor.Set(m_motorSpeed);
    }
    else
    {
        m_arms.Set(true);
        m_motor.Set(0);
    }
}

void Intake::ReverseIntake()
{
    if (m_arms.Get() == true)
    {
        m_motor.Set(-m_motorSpeed);
    }
}

void Intake::RestoreIntakeDirection()
{
    m_motor.Set(m_motorSpeed);
}

