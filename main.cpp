#include <iostream>
#include "S_Cube.h"
#include "R_Cube.h"
#include "M_Cube.h"
#include "H_Cube.h"
#include "Z_Cube.h"
#include "Generator1.h"

using namespace std;

int main()
{
    Generator1 * gen = new S_Cube();

    gen->initGrid(0.05, 0, 0.5, 0, 0.5, 0, 0.5);

    gen->Generate();

    gen->SaveToFileVTK();

    return 0;
}
