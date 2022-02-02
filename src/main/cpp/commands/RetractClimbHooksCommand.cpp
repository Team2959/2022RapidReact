// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/RetractClimbHooksCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
RetractClimbHooksCommand::RetractClimbHooksCommand(ClimbSubsystem & climbSubsytem)
: m_climbSubsytem(climbSubsytem) 
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&climbSubsytem);
}

// Called when the command is initially scheduled.
void RetractClimbHooksCommand::Initialize() 
{
  m_climbSubsytem.RetractClimbHooks();
}