
#include <subsystems/Turret.h>

Turret::Turret()
{
    m_turretEncoder.SetPositionConversionFactor(180); // convert position to degrees
    m_turretController.SetFeedbackDevice(m_turretEncoder);
}

void Turret::DriveDegrees(double degrees)
{
    m_turretController.SetReference(degrees, rev::CANSparkMax::ControlType::kPosition);
}

