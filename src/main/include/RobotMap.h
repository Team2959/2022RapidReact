#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// CAN motor addresses
// constexpr int kRight1CanSparkMaxMotor = 1;

// PWM motor addresses
// constexpr int kClimbWheelsPwmSparkMotor = 1;

// REV Pneumatic Hub solenoid addresses
constexpr int kClimbSolenoid = 1;

// Digital IO addresses
// constexpr int kLiftBottomSwitch = 0;

// Operator input USB ports
constexpr int kButtonBox = 3;

// Co-Pilot Buttons
constexpr int kExtendClimbHooks = 4;
constexpr int kRetractClimbHooks = 5;
