
#include <subsystems/Vision.h>
#include <networktables/NetworkTableInstance.h>
#include <units/angle.h>

Vision::Vision(cwtech::Debug* parent)
     : cwtech::Debug("Vision", parent)
{
}

void Vision::Periodic()
{
    result.PutNumber(GetDistanceFromTargetWithHeight(10_m));
}

double Vision::GetDistanceFromTargetWithHeight(units::meter_t height)
{
    double a2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty",0.0);
    return (h2.GetNumber({0.0}) - h1.GetNumber({0.0})) / tan(DegreesToRadians(a1.GetNumber({0.0}) + a2));
}
