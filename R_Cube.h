#pragma once
#include "Generator1.h"

class R_Cube :public Generator1
{
public:

    R_Cube(double minimum, double maximum, int dalys);
    ~R_Cube();

    double r_min, r_max;
    int parts;
    void Generate();
};
