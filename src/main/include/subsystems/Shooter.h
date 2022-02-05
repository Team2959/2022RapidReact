#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxAnalogSensor.h>
#include <frc/controller/PIDController.h>
#include <frc/AnalogEncoder.h>
#include <cwtech/Debug.h>
#include <wpi/numbers>
#include <frc/DigitalInput.h>
#include <frc/DutyCycle.h>
#include <frc/Solenoid.h>

class Shooter : public frc2::SubsystemBase, public cwtech::Debug
{
public:
    Shooter(cwtech::Debug* parent = nullptr);
    void Periodic() override;
    void OnStartup();
    void SetSpeed(double velocity);
    void Feed(bool value);
    double GetSpeed();
private:
    rev::CANSparkMax m_left{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_right{8, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxPIDController m_controller = m_left.GetPIDController();
    rev::SparkMaxRelativeEncoder m_encoder{m_left.GetEncoder()};
    frc::Solenoid m_feeder{frc::PneumaticsModuleType::REVPH, 1}; // TODO actual value
};
