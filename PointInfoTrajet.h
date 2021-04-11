#ifndef POINTINFOTRAJET_H_INCLUDED
#define POINTINFOTRAJET_H_INCLUDED
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
class PointInfoTrajet
{
public:
    PointInfoTrajet(std::string type , float temps);
    ~PointInfoTrajet();
    /// Getter
    float getPointInfoTemps();
    std::string getPointInfoType();


    private:
    std::string m_type;
    float m_temps;
};

#endif // POINTINFOTRAJET_H_INCLUDED
