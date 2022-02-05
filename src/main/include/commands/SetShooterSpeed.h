#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"

#include "OI.h"

// This command will allow you to set a velocity and it will run until the Shooter reaches it
class SetShooterSpeed : public frc2::CommandHelper<frc2::CommandBase, SetShooterSpeed> {
public:
    explicit SetShooterSpeed(double speed, Shooter& shooter, OI& oi);
    void Initialize() override;
    bool IsFinished() override;
    void End(bool interupt);
private:
    Shooter& m_shooter;
    OI& m_oi;
    double m_speed;
};
