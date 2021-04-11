
#include "PointInfoTrajet.h"

PointInfoTrajet::PointInfoTrajet(std::string type , float temps)
{
     m_type=type;
     m_temps=temps;
}

PointInfoTrajet::~PointInfoTrajet(){}
float PointInfoTrajet::getPointInfoTemps()
{
    return m_temps;
}
std::string PointInfoTrajet::getPointInfoType()
{
    return m_type;
}
