#pragma once

#include <cmath>


namespace cwtech
{

template<unsigned long long Precision = 10000>
bool fcompare(double left, double right)
{
    constexpr double  precision = 1.0 / Precision;
    return std::fabs(left - right) > precision;
}

}