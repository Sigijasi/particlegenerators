#include "Hexagonal_cube.h"

#include "Generator1.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
Hexagonal_cube::Hexagonal_cube()
{
}
Hexagonal_cube::~Hexagonal_cube()
{
}
void Hexagonal_cube::Generate()
{
    double atstumas_tarp_tasku = 0, a = 0, b = 0;

    atstumas_tarp_tasku = (Radius - (sqrt((Radius * Radius) / 2))) * 2;

    for(int i = 1; i <= 1; i++)
    {
        a = (i * cell_size) + (Radius - atstumas_tarp_tasku);

        for(int j = 1; j <= Ny - 1; j++)
        {
            b = j * cell_size;

            for(int k = 1; k <= Nz - 1; k++)
            {
                x_Points.push_back(a);
                y_Points.push_back(b);
                z_Points.push_back(k * cell_size);
            }
        }
    }

    double atstumo_skirtumas = (Radius + (Radius - atstumas_tarp_tasku));

    double a1 = 0, o = 3;

    a = 0;

    b = 0;

    for(int i = 2; i <= Nx - 1; i++)
    {
        a1 = Radius + (atstumo_skirtumas * o);

        for(int j = 1; j <= Ny - 1; j++)
        {
           b = j * cell_size;

            for(int k = 1; k <= Nz - 1; k++)
            {
                if(a1 <= Nx1)
                {
                    x_Points.push_back(a1);
                    y_Points.push_back(b);
                    z_Points.push_back(k * cell_size);
                }
            }
        }
        o+= 2;
    }

    b = 0;

    for(int i = 0; i < 1; i++)
    {
        a = (i * cell_size) + Radius;

        for(int j = 0; j < Ny; j++)
        {
            b = (j * cell_size) + Radius;

            for(int k = 0; k < Nz; k++)
            {
                x_Points.push_back(a);

                y_Points.push_back(b);

                z_Points.push_back((k * cell_size) + Radius);
            }
        }
    }

    double p = 2, a2 = 0, c = 0;

    b = 0;

    for(int i = 1; i < Nx; i++)
    {
        a2 = Radius + (atstumo_skirtumas * p);

        for(int j = 0; j < Ny; j++)
        {
            b = (j * cell_size) + Radius;

            for(int k = 0; k < Nz; k++)
            {
                c = (k * cell_size) + Radius;

                if(a2 <= Nx1)
                {
                    x_Points.push_back(a2);

                    y_Points.push_back(b);

                    z_Points.push_back(c);
                }
            }
        }
        p += 2;
    }

    for(int i = 0; i < x_Points.size(); i++)
    {

    }

    Number_Of_Points = x_Points.size();
    parts = 1;

    for(int i = 0; i < Number_Of_Points; i++)
    {
        Skirtingi_spinduliai.push_back(Radius);
        Daleliu_ID.push_back(0);
    }

    parts = 1;
}
