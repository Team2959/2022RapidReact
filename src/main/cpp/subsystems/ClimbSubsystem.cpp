// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimbSubsystem.h"

ClimbSubsystem::ClimbSubsystem() = default;

// This method will be called once per scheduler run
void ClimbSubsystem::Periodic() {}

void ClimbSubsystem::ExtendClimbHooks()
{
    m_climbSolenoid.Set(true);
}
void ClimbSubsystem::RetractClimbHooks()
{
    m_climbSolenoid.Set(false);
}