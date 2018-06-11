#pragma once
#include "Generator1.h"
#include <vector>
#include <random>

class R_Cube :public Generator1
{
public:
    R_Cube(double minimum, double maximum, int dalys);
    ~R_Cube();

    double r_min;
    double r_max;

    int v2;



    void Generate();
};
