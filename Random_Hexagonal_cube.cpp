#include "Random_Hexagonal_cube.h"
#include "Generator1.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

Random_Hexagonal_cube::Random_Hexagonal_cube(double minimum, double maximum, int dalys)
{
    parts = dalys;
    r_min = minimum;
    r_max = maximum;
}

Random_Hexagonal_cube::~Random_Hexagonal_cube()
{
}

void Random_Hexagonal_cube::Generate()
{
    for(int i = 0; i < Nx; i++)
    {
        long double a;
        a = (i * cell_size) + Radius;

        for(int j = 0; j < Ny; j++)
        {
            long double b = 0;
            b = (j * cell_size) + Radius;

            for(int z = 0; z < Nz; z++)
            {
                long double c = 0;
                c = (z * cell_size) + Radius;

                x_Points.push_back(a);
                y_Points.push_back(b);
                z_Points.push_back(c);
            }
        }
    }

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(r_min, r_max);

    for(int n = 0; n < parts; n++)
    {
        Random_radius.push_back(distr(eng));
    }

    for(int i = 0; i < x_Points.size(); i++)
    {
        int v2;
        v2 = rand() % parts + 0;
        Skirtingi_spinduliai.push_back(Random_radius[v2]);
        Daleliu_ID.push_back(v2);
    }

    temp = 1;
}
