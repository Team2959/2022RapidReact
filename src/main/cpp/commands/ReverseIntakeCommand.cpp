// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReverseIntakeCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ReverseIntakeCommand::ReverseIntakeCommand(Intake & intake) 
: m_intake(intake)
{
  AddRequirements(&intake);
}

// Called when the command is initially scheduled.
void ReverseIntakeCommand::Initialize() 
{
  m_intake.ReverseIntake();
}

void ReverseIntakeCommand::End(bool interupt)
{
  m_intake.RestoreIntakeDirection();
}
