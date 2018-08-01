#include "H_Cube.h"
#include "Generator1.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

H_Cube::H_Cube()
{

}
H_Cube::~H_Cube()
{

}

void H_Cube::Generate()
{
    double atstumas_tarp_tasku = sqrt(pow(2 * Radius, 2) + pow(2 * Radius, 2));
    double puse_atstumo = atstumas_tarp_tasku / 2;

    for(int i = 0; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz; k++)
            {
                x_Points.push_back(i * atstumas_tarp_tasku);
                y_Points.push_back(j * atstumas_tarp_tasku);
                z_Points.push_back(k * atstumas_tarp_tasku);
            }
        }
    }

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            for(int k = 0 ; k < Nz - 1; k++)
            {
                x_Points.push_back(0);
                y_Points.push_back(j * atstumas_tarp_tasku + puse_atstumo);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            for(int k = 0 ; k < Nz - 1; k++)
            {
                x_Points.push_back(i * atstumas_tarp_tasku);
                y_Points.push_back(j * atstumas_tarp_tasku + puse_atstumo);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            for(int k = 0 ; k < Nz - 1; k++)
            {
                y_Points.push_back(0);
                x_Points.push_back(j * atstumas_tarp_tasku + puse_atstumo);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            for(int k = 0 ; k < Nz - 1; k++)
            {
                y_Points.push_back(i * atstumas_tarp_tasku);
                x_Points.push_back(j * atstumas_tarp_tasku + puse_atstumo);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            for(int k = 0 ; k < Nz - 1; k++)
            {
                z_Points.push_back(0);
                y_Points.push_back(j * atstumas_tarp_tasku + puse_atstumo);
                x_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            for(int k = 0 ; k < Nz - 1; k++)
            {
                z_Points.push_back(i * atstumas_tarp_tasku);
                y_Points.push_back(j * atstumas_tarp_tasku + puse_atstumo);
                x_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    pirma_dalis = x_Points.size();

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz - 1; k++)
            {
                x_Points.push_back(0);
                y_Points.push_back(j * atstumas_tarp_tasku);
                z_Points.push_back((k * atstumas_tarp_tasku) + puse_atstumo);
            }
        }
    }

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz - 1; k++)
            {
                x_Points.push_back(i * atstumas_tarp_tasku);
                y_Points.push_back(j * atstumas_tarp_tasku);
                z_Points.push_back((k * atstumas_tarp_tasku) + puse_atstumo);
            }
        }
    }

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz - 1; k++)
            {
                y_Points.push_back(0);
                z_Points.push_back(j * atstumas_tarp_tasku);
                x_Points.push_back((k * atstumas_tarp_tasku) + puse_atstumo);
            }
        }
    }

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz - 1; k++)
            {
                y_Points.push_back(i * atstumas_tarp_tasku);
                z_Points.push_back(j * atstumas_tarp_tasku);
                x_Points.push_back((k * atstumas_tarp_tasku) + puse_atstumo);
            }
        }
    }

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz - 1; k++)
            {
                z_Points.push_back(0);
                x_Points.push_back(j * atstumas_tarp_tasku);
                y_Points.push_back((k * atstumas_tarp_tasku) + puse_atstumo);
            }
        }
    }

    for(int i = 1; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            for(int k = 0; k < Nz - 1; k++)
            {
                z_Points.push_back(i * atstumas_tarp_tasku);
                x_Points.push_back(j * atstumas_tarp_tasku);
                y_Points.push_back((k * atstumas_tarp_tasku) + puse_atstumo);
            }
        }
    }

    Number_Of_Points = x_Points.size();

    radiusHcube = puse_atstumo - Radius;

    Random_radius.push_back(Radius);
    Random_radius.push_back(puse_atstumo - Radius);
    parts = 2;

    for(int i = 0; i < pirma_dalis; i++)
    {
        Skirtingi_spinduliai.push_back(Radius);
        Daleliu_ID.push_back(0);
    }

    for(int i = pirma_dalis; i < x_Points.size(); i++)
    {
        Skirtingi_spinduliai.push_back(puse_atstumo - Radius);
        Daleliu_ID.push_back(1);
    }

    temp = 1;
}
