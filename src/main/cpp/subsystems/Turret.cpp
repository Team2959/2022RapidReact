
#include <subsystems/Turret.h>
#include <wpi/math>
#include <iostream>

Turret::Turret(cwtech::Debug* parent)
    : cwtech::Debug("Turret", parent)
{
    m_turretEncoder.SetPositionConversionFactor(4096 / 360);
}

void Turret::DriveDegrees(double degrees)
{
    //auto destination = m_turretEncoder.GetDistance() + degrees;
    //if(destination > TurretMax || destination < TurretMin)
    //{
    //}
    //m_turretController.SetSetpoint(degrees);
}

void Turret::Periodic()
{
    auto value = m_turretEncoder.GetPosition();

    //std::cerr << value << std::endl;
    m_rawAnalogOutput.PutNumber(m_turretEncoder.GetPosition());
    //m_analogDistance.PutNumber(m_turretEncoder.GetPosition() * (360 / 4.62));
    m_relativeEncoder.PutNumber(m_turretRelativeEncoder.GetPosition());
    m_motorOuput.PutNumber(m_turretMotor.Get());
    /*if(!m_turretController.AtSetpoint())
    {
        m_turretMotor.Set(m_turretController.Calculate(m_turretEncoder.GetDistance()));
    }*/
}

void Turret::OnStartup()
{
    m_initalAnalogOutput.PutNumber(m_turretEncoder.GetPosition());
}
