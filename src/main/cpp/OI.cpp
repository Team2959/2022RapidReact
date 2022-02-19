
#include "OI.h"
#include <frc2/command/button/JoystickButton.h>
#include <commands/ExtendClimbHooksCommand.h>
#include <commands/RetractClimbHooksCommand.h>
#include <commands/IntakeToggleCommand.h>
#include <commands/ReverseIntakeCommand.h>

OI::OI(Climb & climbSubsytem, Intake & intakeSubsystem)
{
    m_xConditioning.SetDeadband(0.15);
    m_xConditioning.SetExponent(1.3);
    m_yConditioning.SetDeadband(0.15);
    m_yConditioning.SetExponent(0.8);
    m_rotationConditioning.SetDeadband(0.25);
    m_rotationConditioning.SetExponent(0.8);

    (frc2::JoystickButton(&m_buttonBox, kExtendClimbHooks)).WhenPressed(ExtendClimbHooksCommand(climbSubsytem));
    (frc2::JoystickButton(&m_buttonBox, kRetractClimbHooks)).WhenPressed(RetractClimbHooksCommand(climbSubsytem));
    (frc2::JoystickButton(&m_buttonBox, kIntakeToggle).WhenPressed(IntakeToggleCommand(intakeSubsystem)));
    (frc2::JoystickButton(&m_buttonBox, kReverseIntake).WhenHeld(ReverseIntakeCommand(intakeSubsystem)));
}