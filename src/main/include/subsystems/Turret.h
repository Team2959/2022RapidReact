#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxAnalogSensor.h>

class Turret : public frc2::SubsystemBase
{
public:
    Turret();
    void DriveDegrees(double degrees);
private:
    static constexpr double m_turretMotorEncoderRatio = 1.0 / 462.0;
    rev::CANSparkMax m_turretMotor{29, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxPIDController m_turretController = m_turretMotor.GetPIDController();
    rev::SparkMaxAlternateEncoder m_turretEncoder = m_turretMotor.GetAlternateEncoder(rev::SparkMaxAlternateEncoder::Type::kQuadrature, 462); // the 462 is the ratio
};
