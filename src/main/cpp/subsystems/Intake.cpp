#include <subsystems/Intake.h>

Intake::Intake(cwtech::Debug* parent)
    : cwtech::Debug("Intake", parent)
{
}

void Intake::Extend()
{
    m_arms.Set(true);
}

void Intake::Retract()
{
    m_arms.Set(false);
}

void Intake::Start()
{
    m_motor.Set(m_motorSpeed);
}

void Intake::Stop()
{
    m_motor.Set(0);
}

