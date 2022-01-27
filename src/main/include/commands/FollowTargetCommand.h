#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Vision.h"

#include "OI.h"

class FollowTargetCommand : public frc2::CommandHelper<frc2::CommandBase, FollowTargetCommand> {
public:
    explicit FollowTargetCommand(Vision* drivetrain, OI& oi);
    void Execute() override;
    void End(bool interupt);
private:
    Vision* m_vision;
    OI& m_oi;
};
