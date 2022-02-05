#pragma once

#include <frc2/command/SubsystemBase.h>
#include <cwtech/Debug.h>
#include <frc/Solenoid.h>
#include <rev/CANSparkMax.h>

class Intake : public frc2::SubsystemBase, public cwtech::Debug
{
public:
    Intake(cwtech::Debug* parent = nullptr);
    void Extend();
    void Retract();
    void Start();
    void Stop();
private:
    static constexpr double m_motorSpeed = 0.2;
    frc::Solenoid m_arms{frc::PneumaticsModuleType::REVPH, 1}; // TODO actual value
    rev::CANSparkMax m_motor{56, rev::CANSparkMax::MotorType::kBrushless}; // TODO actual value
};