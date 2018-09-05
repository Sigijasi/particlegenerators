 
#pragma once
#include "Generator1.h"

class Random_Hexagonal_cube :public Generator1
{
public:

    Random_Hexagonal_cube(double minimum, double maximum, int dalys);
    ~Random_Hexagonal_cube();

    double r_min, r_max;
    int parts;
    void Generate();
};

