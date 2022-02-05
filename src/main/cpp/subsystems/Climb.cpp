// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climb.h"

Climb::Climb() = default;

// This method will be called once per scheduler run
void Climb::Periodic() {}

void Climb::ExtendClimbHooks()
{
    m_climbSolenoid.Set(true);
}
void Climb::RetractClimbHooks()
{
    m_climbSolenoid.Set(false);
}