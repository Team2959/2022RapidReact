
#pragma once

#include <units/length.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

static constexpr double PI{ 3.14159265359 };
static constexpr double DegreesToRadiansFactor{ PI / 180.0 };

static constexpr double DegreesToRadians(double degrees) { return degrees * DegreesToRadiansFactor; }
static constexpr double RadiansToDegrees(double radians) { return radians / DegreesToRadiansFactor; }

#include <cwtech/Debug.h>

class Vision : public cwtech::Debug, public frc2::SubsystemBase
{
private:
    // Angle of Mounted Limelight(Degrees)
    cwtech::DebugVariable a1 = Variable("Camera Angle", {0.0});
    // Height of Limelight(1m)
    cwtech::DebugVariable h1 = Variable("Camera Height", {0.0});
    cwtech::DebugVariable h2 = Variable("Target Height", {0.0});
    cwtech::DebugVariable result = Variable("Target Distance", {0.0});

public:
    //rev::CANSparkMax m_turret{29, rev::CANSparkMax::MotorType::kBrushless};

    Vision(cwtech::Debug* parent = nullptr);
    void Periodic() override;
    double GetDistanceFromTargetWithHeight(units::meter_t height);

};
