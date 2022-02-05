
#include <commands/SetShooterSpeed.h>
#include <cwtech/Util.h>

SetShooterSpeed::SetShooterSpeed(double speed, Shooter& shooter, OI& oi)
    : m_shooter(shooter), m_oi(oi), m_speed(speed)
{
    AddRequirements(&m_shooter);
}

void SetShooterSpeed::Initialize()
{
    m_shooter.SetSpeed(m_speed);
}

bool SetShooterSpeed::IsFinished()
{
    return cwtech::fcompare(m_shooter.GetSpeed(), m_speed);
}

void SetShooterSpeed::End(bool)
{
    // do nothing here
}


