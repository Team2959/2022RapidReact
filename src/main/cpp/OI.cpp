
#include "OI.h"

OI::OI()
{
    m_xConditioning.SetDeadband(0.15);
    m_xConditioning.SetExponent(1.3);
    m_yConditioning.SetDeadband(0.15);
    m_yConditioning.SetExponent(0.8);
    m_rotationConditioning.SetDeadband(0.15);
    m_rotationConditioning.SetExponent(0.8);
}