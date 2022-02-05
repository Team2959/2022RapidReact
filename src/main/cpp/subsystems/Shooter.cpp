
#include <subsystems/Shooter.h>
#include <iostream>

Shooter::Shooter(cwtech::Debug* parent)
    : cwtech::Debug("Shooter", parent)
{
    m_right.Follow(m_left, true);
}

void Shooter::SetSpeed(double velocity)
{
    m_controller.SetReference(velocity, rev::CANSparkMax::ControlType::kVelocity);
}

void Shooter::Feed(bool value)
{
    m_feeder.Set(value);
}

void Shooter::Periodic()
{
}

void Shooter::OnStartup()
{
}

double Shooter::GetSpeed()
{
    return m_encoder.GetVelocity();
}