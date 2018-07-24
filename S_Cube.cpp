#include "S_Cube.h"
#include "Generator1.h"
#include <iostream>

using namespace std;

S_Cube::S_Cube()
{

}

S_Cube::~S_Cube()
{

}

void S_Cube::Generate()
{
    for(int i = 0; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int z = 0; z < Nz; z++)
            {
                x_Points.push_back((i * cell_size) + Radius);
                y_Points.push_back((j * cell_size) + Radius);
                z_Points.push_back((z * cell_size) + Radius);
            }
        }
    }

    Number_Of_Points = Nx * Ny * Nz;

    for(int i = 0; i < Number_Of_Points; i++)
    {
        Skirtingi_spinduliai.push_back(Radius);
        Daleliu_ID.push_back(0);
    }
}
