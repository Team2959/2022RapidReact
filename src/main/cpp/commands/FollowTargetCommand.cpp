#include <commands/FollowTargetCommand.h>
#include <networktables/NetworkTableInstance.h>

#include <iostream>

FollowTargetCommand::FollowTargetCommand(Vision* vision, Turret* turret, OI& oi)
    : m_vision(vision), m_oi(oi), m_turret(turret)
{
    AddRequirements(m_vision);
    AddRequirements(m_turret);
}

void FollowTargetCommand::Execute()
{
    double a = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx",0.0);
    m_turret->SetDesiredAngle(units::degree_t{a});
}

void FollowTargetCommand::End(bool interupt)
{
    //m_vision->m_turret.Set(0);
}