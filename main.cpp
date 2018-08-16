#include <iostream>
#include "S_Cube.h"
#include "R_Cube.h"
#include "M_Cube.h"
#include "H_Cube.h"
#include "Z_Cube.h"
#include "J_Cube.h"
#include "Generator1.h"

#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    clock_t start = clock();

    Generator1 * gen = new S_Cube();

    gen->initGrid(0.7, 0, 8, 0, 8, 0, 8);

    gen->Generate();

    //-----------------------------------------------------------------------------------------------------------------------------------------
    //gen->UniformGrid();
    //-----------------------------------------------------------------------------------------------------------------------------------------

    gen->SaveToFileVTK();

    printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
