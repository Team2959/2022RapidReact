#include <commands/TeleopDriveCommand.h>

TeleopDriveCommand::TeleopDriveCommand(Drivetrain* drivetrain, OI& oi)
    : m_drivetrain(drivetrain), m_oi(oi)
{
    AddRequirements(m_drivetrain);
}

void TeleopDriveCommand::Execute()
{
        // Get the x speed. We are inverting this because Xbox controllers return
        // negative values when we push forward.
        auto x = m_oi.m_xboxController.GetLeftX();
        x = -m_oi.m_xConditioning.Condition(x);
        auto xSpeed = x * Drivetrain::kMaxSpeed;

        // Get the y speed or sideways/strafe speed. We are inverting this because
        // we want a positive value when we pull to the left. Xbox controllers
        // return positive values when you pull to the right by default.
        auto y = m_oi.m_xboxController.GetLeftY();
        y = m_oi.m_yConditioning.Condition(y);
        auto ySpeed = y * Drivetrain::kMaxSpeed;

        // Get the rate of angular rotation. We are inverting this because we want a
        // positive value when we pull to the left (remember, CCW is positive in
        // mathematics). Xbox controllers return positive values when you pull to
        // the right by default.
        auto r = m_oi.m_xboxController.GetRightX();
        r = m_oi.m_rotationConditioning.Condition(r);
        auto rot = -r * Drivetrain::kMaxAngularSpeed;
        m_drivetrain->Drive(xSpeed, ySpeed, rot, true);
}

void TeleopDriveCommand::End(bool interupt)
{
    m_drivetrain->Drive(0_mps, 0_mps, units::radians_per_second_t{0}, true);
}