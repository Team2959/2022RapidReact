#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <frc/DutyCycle.h>
#include <RobotMap.h>

class Hood : public frc2::SubsystemBase
{
public:
    Hood();
private:
    frc::DigitalInput m_dutyCycleInput{kHoodPulseWidthDigIo};
    frc::DutyCycle m_dutyCycle{m_dutyCycleInput};
};
