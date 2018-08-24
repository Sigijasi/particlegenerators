#pragma once
#include "Generator1.h"

class Face_Centered_cube :public Generator1
{
public:

    Face_Centered_cube();
    ~Face_Centered_cube();

    void Generate();
};
