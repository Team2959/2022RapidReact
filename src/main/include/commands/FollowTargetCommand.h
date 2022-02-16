#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Vision.h"
#include "subsystems/Turret.h"

#include "OI.h"

class FollowTargetCommand : public frc2::CommandHelper<frc2::CommandBase, FollowTargetCommand> {
public:
    explicit FollowTargetCommand(Vision* drivetrain, Turret* turret, OI& oi);
    void Execute() override;
    void End(bool interupt);
private:
    Vision* m_vision;
    Turret* m_turret;
    OI& m_oi;
};
