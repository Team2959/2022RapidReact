#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxAnalogSensor.h>
#include <frc/controller/PIDController.h>
#include <frc/AnalogEncoder.h>
#include <cwtech/Debug.h>
#include <wpi/numbers>

class Turret : public frc2::SubsystemBase, public cwtech::Debug
{
public:
    Turret(cwtech::Debug* parent = nullptr);
    void DriveDegrees(double degrees);
    void Periodic() override;
    void OnStartup();
private:
    static constexpr double TurretMin = -wpi::numbers::pi;
    static constexpr double TurretMax = wpi::numbers::pi;
    static constexpr double m_turretMotorEncoderRatio = 1.0 / 462.0;
    rev::CANSparkMax m_turretMotor{29, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxRelativeEncoder m_turretRelativeEncoder = m_turretMotor.GetEncoder();
    rev::SparkMaxAnalogSensor m_turretEncoder = m_turretMotor.GetAnalog(); 
    frc2::PIDController m_turretController{1, 0, 0};

    cwtech::DebugVariable m_rawAnalogOutput = Variable("Analog Encoder Output", 0.0);
    cwtech::DebugVariable m_analogDistance = Variable("Analog Encoder Distance", 0.0);
    cwtech::DebugVariable m_relativeEncoder = Variable("Relative Encoder Output", 0.0);
    cwtech::DebugVariable m_motorOuput = Variable("Direct Motor Output", 0.0);
    cwtech::DebugVariable m_initalAnalogOutput = Variable("Inital Analog Encoder Output", 0.0);
};
