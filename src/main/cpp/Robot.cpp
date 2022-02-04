// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <Robot.h>

#include <commands/TeleopDriveCommand.h>
#include <commands/FollowTargetCommand.h>

Robot::Robot() : cwtech::Debug("Robot")
{
}

void Robot::RobotInit()
{
    m_swerve.SetDefaultCommand(TeleopDriveCommand(&m_swerve, m_oi));
    m_vision.SetDefaultCommand(FollowTargetCommand(&m_vision, m_oi));
    m_turret.OnStartup();
    m_swerve.Startup();
}

void Robot::RobotPeriodic()
{
    frc2::CommandScheduler::GetInstance().Run();
}

void Robot::AutonomousPeriodic()
{
    // DriveWithJoystick(false);
}

void Robot::TeleopInit()
{
    m_logging.StartNewLogFile();
    if (!m_haveSetInitalPositions)
    {
        m_swerve.SetInitialSwervePositions();
        m_haveSetInitalPositions = true;
    }
    m_swerve.UpdateDashboardOnUpdate();
    m_startTimestamp = std::chrono::duration_cast<std::chrono::milliseconds>(hal::fpga_clock::now().time_since_epoch()).count();
}

void Robot::TeleopPeriodic()
{
    // DriveWithJoystick(true);
    auto logLine = m_swerve.OutputOdometry();
    m_logging.Log(logLine);
}

void Robot::TestPeriodic()
{
    // auto drive = m_testDriveOrTurn.GetBoolean(true);
    // auto motor = (int)m_testMotorCorner.GetNumber(1.0);
    // auto percentage = m_testMotorPercentage.GetNumber(0.0);

    // m_swerve.DirectMotorDrive(drive, motor, percentage);
}

void Robot::DriveWithJoystick(bool fieldRelative)
{
    // Get the x speed. We are inverting this because Xbox controllers return
    // negative values when we push forward.
    auto x = m_joystick.GetX();
    x = -m_conditioning.Condition(x);
    auto xSpeed = x * Drivetrain::kMaxSpeed;

    // Get the y speed or sideways/strafe speed. We are inverting this because
    // we want a positive value when we pull to the left. Xbox controllers
    // return positive values when you pull to the right by default.
    auto y = m_joystick.GetY();
    y = m_conditioning.Condition(y);
    auto ySpeed = y * Drivetrain::kMaxSpeed;

    // Get the rate of angular rotation. We are inverting this because we want a
    // positive value when we pull to the left (remember, CCW is positive in
    // mathematics). Xbox controllers return positive values when you pull to
    // the right by default.
    auto r = m_joystick.GetTwist();
    r = m_conditioning.Condition(r);
    auto rot = -r * Drivetrain::kMaxAngularSpeed;
    m_swerve.Drive(xSpeed, ySpeed, rot, fieldRelative);
}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif
