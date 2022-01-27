#include <commands/FollowTargetCommand.h>
#include <networktables/NetworkTableInstance.h>

#include <iostream>

FollowTargetCommand::FollowTargetCommand(Vision* vision, OI& oi)
    : m_vision(vision), m_oi(oi)
{
    AddRequirements(m_vision);
}

void FollowTargetCommand::Execute()
{
    double a = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx",0.0);
    if(a < 2 && a > -2)
    {
        m_vision->m_turret.Set(0.0);
    }
    else
    {
        if(a > 0)
        {
            m_vision->m_turret.Set(0.15);
        }
        else
        {
            m_vision->m_turret.Set(-0.15);
        }
    }
}

void FollowTargetCommand::End(bool interupt)
{
    m_vision->m_turret.Set(0);
}