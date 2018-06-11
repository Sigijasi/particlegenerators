#include <iostream>
#include "S_Cube.h"
#include "R_Cube.h"

#include "Generator1.h"

using namespace std;

int main()
{
    Generator1 * gen = new R_Cube(0.1, 0.6, 10);

    gen->initGrid(0.5, 0, 50, 0, 50, 0, 50); //R_Cube didziausias spindulys irasomas kaip pirmas argumentas.

    gen->Generate();

    gen->SaveToPolyData();

    gen->SaveToFile();

    gen->SaveToFileVTK();

    return 0;
}
