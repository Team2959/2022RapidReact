// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/numbers>
#include <frc/smartdashboard/SendableChooser.h>
#include <AHRS.h>
#include <cwtech/Debug.h>

#include "Constants.h"

#include "subsystems/SwerveModule.h"
#include <frc2/command/SubsystemBase.h>
#include <RobotMap.h>

class Drivetrain : public cwtech::Debug, public frc2::SubsystemBase
{
public:
	enum DriveType
	{
		Xbox,
		Single,
		Double,
	};

	Drivetrain(Debug* parent = nullptr);

	void Drive(units::meters_per_second_t xSpeed,
			   units::meters_per_second_t ySpeed, units::radians_per_second_t rot,
			   bool fieldRelative);
	void UpdateOdometry();
	std::string OutputOdometry();
	void SetInitialSwervePositions();
	void UpdateDashboardOnUpdate();
	void DirectMotorDrive(bool drive, int motor, double percentage);
	void Periodic() override;

	frc::SwerveDriveKinematics<4> GetKinematics()
	{
		return m_kinematics;
	}

	frc::Pose2d GetPose()
	{
		return m_odometry.GetPose();
	}

	frc::Rotation2d GetHeading()
	{
		return m_navX.GetRotation2d();
	}

	double GetGyroAngle()
	{
		return m_navX.GetAngle();
	}

	double GetGyroRate()
	{
		return m_navX.GetRate();
	}

	void ResetOdometry(frc::Pose2d pose)
	{
		m_odometry.ResetPosition(pose, m_navX.GetRotation2d());
	}

	void ResetGyro()
	{
		m_navX.Reset();
	}

	static constexpr units::meters_per_second_t kMaxSpeed =
		1.5_mps; // 3 meters per second
	static constexpr units::radians_per_second_t kMaxAngularSpeed{
		wpi::numbers::pi}; // 1/2 rotation per second

	DriveType GetDriveType();
	bool GetFieldRelative() { return m_fieldCentric.GetBoolean(true); }
	void Startup() { frc::SmartDashboard::PutData("Drive Type", &m_driveType); }
private:
	frc::Translation2d m_frontLeftLocation{+0.381_m, -0.381_m};
	frc::Translation2d m_frontRightLocation{-0.381_m, -0.381_m};
	frc::Translation2d m_backLeftLocation{+0.381_m, +0.381_m};
	frc::Translation2d m_backRightLocation{-0.381_m, +0.381_m};

	cwtech::DebugVariable m_P = Variable("P", 0.0);
	cwtech::DebugVariable m_I = Variable("I", 0.0);
	cwtech::DebugVariable m_D = Variable("D", 0.0);
	cwtech::DebugVariable m_FF = Variable("FF", 0.2);
	cwtech::DebugVariable m_poseX = Variable("Pose/X", 0.0);
	cwtech::DebugVariable m_poseY = Variable("Pose/Y", 0.0);

	SwerveModule m_frontLeft{kFrontLeftDriveCanSparkMaxMotor, kFrontLeftTurnCanSparkMaxMotor, kFrontLeftTurnPulseWidthDigIo, "Front Left", ZeroedFrontLeft, this};
	SwerveModule m_frontRight{kFrontRightDriveCanSparkMaxMotor, kFrontRightTurnCanSparkMaxMotor, kFrontRightTurnPulseWidthDigIo, "Front Right", ZeroedFrontRight, this};
	SwerveModule m_backRight{kBackRightDriveCanSparkMaxMotor, kBackRightTurnCanSparkMaxMotor, kBackRightTurnPulseWidthDigIo, "Back Right", ZeroedBackRight, this};
	SwerveModule m_backLeft{kBackLeftDriveCanSparkMaxMotor, kBackLeftTurnCanSparkMaxMotor, kBackLeftTurnPulseWidthDigIo, "Back Left", ZeroedBackLeft, this};

	AHRS m_navX{frc::SPI::kMXP};

	frc::SwerveDriveKinematics<4> m_kinematics{
		m_frontLeftLocation, m_frontRightLocation, m_backLeftLocation,
		m_backRightLocation};

	frc::SwerveDriveOdometry<4> m_odometry{m_kinematics, m_navX.GetRotation2d()};

	frc::SendableChooser<DriveType> m_driveType;
	cwtech::DebugVariable m_fieldCentric = Variable("Field Relative", true);

};
