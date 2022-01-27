#pragma once

#include <frc/Joystick.h>
#include <cwtech/Conditioning.h>
#include <frc/XboxController.h>

class OI
{
public:
    OI();
    //frc::Joystick m_joystick{0};
    cwtech::UniformConditioning m_xConditioning{};
    cwtech::UniformConditioning m_yConditioning{};
    cwtech::UniformConditioning m_rotationConditioning{};
    frc::XboxController m_xboxController{0};
};
