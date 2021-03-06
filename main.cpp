#include <iostream>

#include "Regular_cube.h"
#include "Hexagonal_cube.h"
#include "Random_Hexagonal_cube.h"
#include "Face_Centered_cube.h"
#include "Diamond_Structure_cube.h"

#include "Generator1.h"

#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    clock_t start = clock();

    Generator1 * gen = new Hexagonal_cube();

    gen->initGrid(0.05, 0, 2, 0, 2, 0, 2);

    gen->Generate();

    gen->SaveToFileVTK();

    printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
