#include "M_Cube.h"
#include "Generator1.h"
#include <iostream>

using namespace std;

M_Cube::M_Cube()
{
}
M_Cube::~M_Cube()
{
}

void M_Cube::Generate()
{
    int Nx_mid, Ny_mid, Nz_mid;

    Nx_mid = Nx - 1;
    Ny_mid = Ny - 1;
    Nz_mid = Nz - 1;

    for(int i = 1; i <= Nx_mid; i++)
    {
        for(int j = 1; j <= Ny_mid; j++)
        {
            for(int k = 1; k <= Nz_mid; k++)
            {
                x_Points.push_back(i * cell_size);

                y_Points.push_back(j * cell_size);

                z_Points.push_back(k * cell_size);
            }
        }
    }

    for(int i = 0; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz; k++)
            {
                x_Points.push_back((i * cell_size) + Radius);

                y_Points.push_back((j * cell_size) + Radius);

                z_Points.push_back((k * cell_size) + Radius);
            }
        }
    }

    Number_Of_Points = x_Points.size();

    for(int i = 0; i < Number_Of_Points; i++)
    {
        Skirtingi_spinduliai.push_back(Radius);

        Daleliu_ID.push_back(0);
    }
}









