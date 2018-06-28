#include <iostream>
#include "S_Cube.h"
#include "R_Cube.h"
#include "M_Cube.h"

#include "Generator1.h"

using namespace std;

int main()
{
    Generator1 * gen = new M_Cube();

    gen->initGrid(0.25, 0, 4, 0, 4, 0, 4); //R_Cube didziausias spindulys irasomas kaip pirmas argumentas.

    gen->Generate();

    gen->SaveToFileVTK();

    return 0;
}
