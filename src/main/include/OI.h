#pragma once

#include <frc/Joystick.h>
#include <cwtech/Conditioning.h>
#include <frc/XboxController.h>
#include <RobotMap.h>
#include <subsystems/Climb.h>
#include <subsystems/Intake.h>


class OI
{
public:
    OI(Climb & climbSubsytem, Intake & intakeSubsystem);
    cwtech::UniformConditioning m_xConditioning{};
    cwtech::UniformConditioning m_yConditioning{};
    cwtech::UniformConditioning m_rotationConditioning{};
    frc::XboxController m_xboxController{0};
    frc::Joystick m_leftJoystick{1};
    frc::Joystick m_rightJoystick{2};
    frc::Joystick m_buttonBox{kButtonBox};
};
