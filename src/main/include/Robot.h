#pragma once

#include <frc/filter/SlewRateLimiter.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/Joystick.h>

#include "cwtech/Conditioning.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Vision.h"
#include <subsystems/Turret.h>
#include <subsystems/Climb.h>
#include <subsystems/Intake.h>
#include <subsystems/Shooter.h>
#include "cwtech/Logging.h"
#include <cwtech/Debug.h>
#include <OI.h>

class Robot : public frc::TimedRobot, public cwtech::Debug
{
public:
    Robot();

    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

private:
    // frc::XboxController m_controller{0};
    frc::Joystick m_joystick{0};
    cwtech::UniformConditioning m_conditioning{};
    Drivetrain m_swerve{this};
    Logging m_logging;
    Vision m_vision{this};
    Turret m_turret{this};
    Climb m_climbSubsystem{};
    Shooter m_shooter{this};
    Intake m_intake{this};

    OI m_oi{m_climbSubsystem, m_intake};
    

    cwtech::DebugVariable m_debugX = Variable("Joystick/X", {0.0});
    cwtech::DebugVariable m_debugY = Variable("Joystick/Y", {0.0});
    cwtech::DebugVariable m_testDriveOrTurn = Variable("Test/Drive or Turn", {true});
    cwtech::DebugVariable m_testMotorCorner = Variable("Test/Test Motor Corner", {1.0});
    cwtech::DebugVariable m_testMotorPercentage = Variable("Test/Motor Percentage", {0.0});
    cwtech::DebugVariable m_time = Variable("Runtime", 0.0);
    cwtech::DebugVariable m_testShooter = Variable("Test/Shooter Velocity", 0.0);
    cwtech::DebugVariable m_testRun = Variable("Test/Shooter Run", false);
    double m_startTimestamp = 0;
    bool m_haveSetInitalPositions = false;

    // Slew rate limiters to make joystick inputs more gentle; 1/3 sec from 0
    // to 1.
    frc::SlewRateLimiter<units::scalar> m_xspeedLimiter{3 / 1_s};
    frc::SlewRateLimiter<units::scalar> m_yspeedLimiter{3 / 1_s};
    frc::SlewRateLimiter<units::scalar> m_rotLimiter{3 / 1_s};

    void DriveWithJoystick(bool fieldRelative);
};
