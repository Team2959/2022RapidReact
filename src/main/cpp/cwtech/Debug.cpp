#include <cwtech/Debug.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

namespace cwtech
{

    struct DebugTypePutVistor
    {
        std::string key;
        DebugTypePutVistor(std::string key)
        {
            this->key = key;
        }
        void operator()(double val)
        {
            frc::SmartDashboard::PutNumber(key, val);
        }
        void operator()(std::string val)
        {
            frc::SmartDashboard::PutString(key, val);
        }
        void operator()(bool val)
        {
            frc::SmartDashboard::PutBoolean(key, val);
        }
        template<typename T>
        void operator()(T t)
        {
            std::cerr << "DebugTypePutVistor: Invalid Smartdashboard type" << std::endl;
        }
    };

    DebugVariable::DebugVariable(std::string key, DebugType defaultValue)
        : m_key(key), m_defaultValue(defaultValue)
    {
        std::cerr << "cwtech::Debug: Created " << m_key << std::endl;
        DebugTypePutVistor vistor{m_key};
        std::visit(vistor, defaultValue);
    }

    double DebugVariable::GetNumber(DebugType defaultValue)
    {
        return frc::SmartDashboard::GetNumber(m_key, std::get<double>(defaultValue));
    }

    std::string DebugVariable::GetString(DebugType defaultValue)
    {
        return frc::SmartDashboard::GetString(m_key, std::get<std::string>(defaultValue));
    }

    bool DebugVariable::GetBoolean(DebugType defaultValue)
    {
        return frc::SmartDashboard::GetBoolean(m_key, std::get<bool>(defaultValue));
    }

    void DebugVariable::PutNumber(double val)
    {
        frc::SmartDashboard::PutNumber(m_key, val);
    }
        
    void DebugVariable::PutString(std::string val)
    {
        frc::SmartDashboard::PutString(m_key, val);
    }

    void DebugVariable::PutBoolean(bool val)
    {
        frc::SmartDashboard::PutBoolean(m_key, val);
    }

    Debug::Debug(std::string name, Debug* parent)
        : m_name(name)
    {
        std::string key = "";
        if(parent != nullptr)
        {
            m_key = parent->m_key + '/' + m_name;
        }
        else
        {
            m_key = m_name;    
        }
        std::cerr << "cwtech::Debug: Created " << m_key << std::endl;
    }

    DebugVariable Debug::Variable(std::string name, DebugType defaultValue)
    {
        return DebugVariable(m_key + '/' + name, defaultValue);
    }

    std::string Debug::Key(std::string name)
    {
        return m_key + '/' + name;
    }


}
