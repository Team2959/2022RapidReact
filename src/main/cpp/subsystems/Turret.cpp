
#include <subsystems/Turret.h>
#include <iostream>

Turret::Turret(cwtech::Debug* parent)
    : cwtech::Debug("Turret", parent)
{
    m_turretMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    m_turretMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);
    m_turretMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, 270);
    m_turretMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, 270);
    m_turretRelativeEncoder.SetPositionConversionFactor(360);
    m_turretController.SetFeedbackDevice(m_turretRelativeEncoder);
    m_turretController.SetFF(0.1);
}

void Turret::SetDesiredAngle(units::degree_t degrees)
{
    m_turretController.SetReference(degrees.to<double>(), rev::ControlType::kPosition);
}

void Turret::Periodic()
{
    m_relativeEncoder.PutNumber(m_turretRelativeEncoder.GetPosition());
}

void Turret::OnStartup()
{
}
