#include <commands/TeleopDriveCommand.h>

TeleopDriveCommand::TeleopDriveCommand(Drivetrain* drivetrain, OI& oi)
    : m_drivetrain(drivetrain), m_oi(oi)
{
    AddRequirements(m_drivetrain);
}

void TeleopDriveCommand::Execute()
{
    units::meters_per_second_t xSpeed, ySpeed;
    units::radians_per_second_t rot;
    auto driveType = m_drivetrain->GetDriveType();
    
    if(driveType == Drivetrain::DriveType::Xbox)
    {
        auto x = m_oi.m_xboxController.GetLeftX();
        x = -m_oi.m_xConditioning.Condition(x);
        xSpeed = x * Drivetrain::kMaxSpeed;

        auto y = m_oi.m_xboxController.GetLeftY();
        y = m_oi.m_yConditioning.Condition(y);
        ySpeed = y * Drivetrain::kMaxSpeed;

        auto r = m_oi.m_xboxController.GetRightX();
        r = m_oi.m_rotationConditioning.Condition(r);
        rot = -r * Drivetrain::kMaxAngularSpeed;
    }
    else if(driveType == Drivetrain::DriveType::Double)
    {
        auto x = m_oi.m_leftJoystick.GetX();
        x = -m_oi.m_xConditioning.Condition(x);
        xSpeed = x * Drivetrain::kMaxSpeed;

        auto y = m_oi.m_leftJoystick.GetY();
        y = m_oi.m_yConditioning.Condition(y);
        ySpeed = y * Drivetrain::kMaxSpeed;

        auto r = m_oi.m_rightJoystick.GetX();
        r = m_oi.m_rotationConditioning.Condition(r);
        rot = -r * Drivetrain::kMaxAngularSpeed;
    }
    else
    {
        auto x = m_oi.m_rightJoystick.GetX();
        x = -m_oi.m_xConditioning.Condition(x);
        xSpeed = x * Drivetrain::kMaxSpeed;

        auto y = m_oi.m_rightJoystick.GetY();
        y = m_oi.m_yConditioning.Condition(y);
        ySpeed = y * Drivetrain::kMaxSpeed;

        auto r = m_oi.m_rightJoystick.GetTwist();
        r = m_oi.m_rotationConditioning.Condition(r);
        rot = -r * Drivetrain::kMaxAngularSpeed;
    }
    m_drivetrain->Drive(xSpeed, ySpeed, rot, m_drivetrain->GetFieldRelative());
}

void TeleopDriveCommand::End(bool interupt)
{
    m_drivetrain->Drive(0_mps, 0_mps, units::radians_per_second_t{0}, true);
}