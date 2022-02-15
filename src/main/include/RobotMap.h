#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// CAN motor addresses
constexpr int kFrontLeftDriveCanSparkMaxMotor = 1;
constexpr int kFrontRightDriveCanSparkMaxMotor = 2;
constexpr int kBackRightDriveCanSparkMaxMotor = 3;
constexpr int kBackLeftDriveCanSparkMaxMotor = 4;
constexpr int kShooterPrimaryCanSparkMaxMotor = 5;
constexpr int kShooterFollowerCanSparkMaxMotor = 6;
constexpr int kTurretCanSparkMaxMotor = 7;
constexpr int kIntakeCanSparkMaxMotor = 8;
constexpr int kFrontLeftTurnCanSparkMaxMotor = 11;
constexpr int kFrontRightTurnCanSparkMaxMotor = 12;
constexpr int kBackRightTurnCanSparkMaxMotor = 13;
constexpr int kBackLeftTurnCanSparkMaxMotor = 14;

// PWM motor addresses
// constexpr int kClimbWheelsPwmSparkMotor = 1;

// REV Pneumatic Hub solenoid addresses
constexpr int kFeederSolenoid = 0;
constexpr int kClimbSolenoid = 1;
constexpr int kIntakeArmsSolenoid = 2;

// Digital IO addresses
constexpr int kTurretPulseWidthDigIo = 3;
constexpr int kHoodPulseWidthDigIo = 4;
constexpr int kFrontLeftTurnPulseWidthDigIo = 5;
constexpr int kFrontRightTurnPulseWidthDigIo = 6;
constexpr int kBackRightTurnPulseWidthDigIo = 7;
constexpr int kBackLeftTurnPulseWidthDigIo = 8;

// Operator input USB ports
constexpr int kButtonBox = 3;

// Co-Pilot Buttons
constexpr int kExtendClimbHooks = 4;
constexpr int kRetractClimbHooks = 5;
