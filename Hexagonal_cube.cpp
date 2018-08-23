#include "Hexagonal_cube.h"
#include "Generator1.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

Hexagonal_cube::Hexagonal_cube()
{
}

Hexagonal_cube::~Hexagonal_cube()
{
}

void Hexagonal_cube::Generate()
{
    long double a = 0, b = 0, c = 0;

    for(int i = 0; i < Nx; i++)
    {
        a = (i * cell_size) + Radius;

        for(int j = 0; j < Ny; j++)
        {
            b = (j * cell_size) + Radius;

            for(int z = 0; z < Nz; z++)
            {
                x_Points.push_back(a);
                y_Points.push_back(b);

                c = (z * cell_size) + Radius;
                z_Points.push_back(c);
            }
        }
    }

    Number_Of_Points = Nx * Ny * Nz;
    parts = 1;

    for(int i = 0; i < x_Points.size(); i++)
    {
        Skirtingi_spinduliai.push_back(Radius);
        Daleliu_ID.push_back(0);
    }
    cout << "Hexagon" << endl;
}

