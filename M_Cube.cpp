#include "M_Cube.h"
#include "Generator1.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

M_Cube::M_Cube()
{

}

M_Cube::~M_Cube()
{

}

void M_Cube::Generate()
{
    double atstumas_tarp_tasku;
    atstumas_tarp_tasku = (Radius - (sqrt((Radius * Radius) / 2))) * 2;

    for(int i = 1; i <= 1; i++)
    {
        for(int j = 1; j <= Ny - 1; j++)
        {
            for(int k = 1; k <= Nz - 1; k++)
            {
                x_Points.push_back((i * cell_size) + (Radius - atstumas_tarp_tasku));
                y_Points.push_back(j * cell_size);
                z_Points.push_back(k * cell_size);
            }
        }
    }

    double atstumo_skirtumas;
    double o = 3;

    atstumo_skirtumas= (Radius + (Radius - atstumas_tarp_tasku));

    for(int i = 2; i <= Nx - 1; i++)
    {
        for(int j = 1; j <= Ny - 1; j++)
        {
            for(int k = 1; k <= Nz - 1; k++)
            {
                double a1;
                a1 = Radius + (atstumo_skirtumas * o);

                if(a1 <= Nx1)
                {
                    x_Points.push_back(a1);
                    y_Points.push_back(j * cell_size);
                    z_Points.push_back(k * cell_size);
                }
            }
        }
        o+= 2;
    }

    for(int i = 0; i < 1; i++)
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

    double p = 2;

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz; k++)
            {
                double a2;
                a2 = Radius + (atstumo_skirtumas * p);

                if(a2 <= Nx1)
                {
                    x_Points.push_back(a2);
                    y_Points.push_back((j * cell_size) + Radius);
                    z_Points.push_back((k * cell_size) + Radius);
                }
            }
        }
        p += 2;
    }

    Number_Of_Points = x_Points.size();
    parts = 1;

    for(int i = 0; i < Number_Of_Points; i++)
    {
        Skirtingi_spinduliai.push_back(Radius);
        Daleliu_ID.push_back(0);
    }
}

