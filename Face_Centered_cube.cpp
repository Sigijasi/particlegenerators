#include "Face_Centered_cube.h"
#include "Generator1.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Face_Centered_cube::Face_Centered_cube()
{
}

Face_Centered_cube::~Face_Centered_cube()
{
}

void Face_Centered_cube::Generate()
{
    double atstumas_tarp_tasku = sqrt(pow(2 * Radius, 2) + pow(2 * Radius, 2)), puse_atstumo = atstumas_tarp_tasku / 2;

    double a = 0, b = 0;

    for(int i = 0; i < Nx; i++)
    {
        a = i * atstumas_tarp_tasku;

        for(int j = 0; j < Ny; j++)
        {

            b = j * atstumas_tarp_tasku;

            for(int k = 0; k < Nz; k++)
            {
                x_Points.push_back(a);
                y_Points.push_back(b);
                z_Points.push_back(k * atstumas_tarp_tasku);
            }
        }
    }

    a = 0;

    b = 0;

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            b = j * atstumas_tarp_tasku + puse_atstumo;

            for(int k = 0 ; k < Nz - 1; k++)
            {
                x_Points.push_back(a);
                y_Points.push_back(b);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    b = 0;

    for(int i = 1; i < Nx; i++)
    {
        a = i * atstumas_tarp_tasku;

        for(int j = 0; j < Ny - 1; j++)
        {
            b = j * atstumas_tarp_tasku + puse_atstumo;

            for(int k = 0 ; k < Nz - 1; k++)
            {
                x_Points.push_back(a);
                y_Points.push_back(b);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    a = 0;

    b = 0;

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            b = j * atstumas_tarp_tasku + puse_atstumo;

            for(int k = 0 ; k < Nz - 1; k++)
            {
                y_Points.push_back(a);
                x_Points.push_back(b);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    b = 0;

    for(int i = 1; i < Nx; i++)
    {
        a = i * atstumas_tarp_tasku;

        for(int j = 0; j < Ny - 1; j++)
        {
            b = j * atstumas_tarp_tasku + puse_atstumo;

            for(int k = 0 ; k < Nz - 1; k++)
            {
                y_Points.push_back(a);
                x_Points.push_back(b);
                z_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    a = 0;

    b = 0;

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < Ny - 1; j++)
        {
            b = j * atstumas_tarp_tasku + puse_atstumo;

            for(int k = 0 ; k < Nz - 1; k++)
            {
                z_Points.push_back(a);
                y_Points.push_back(b);
                x_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    b = 0;

    for(int i = 1; i < Nx; i++)
    {
        a = i * atstumas_tarp_tasku;

        for(int j = 0; j < Ny - 1; j++)
        {
            b = j * atstumas_tarp_tasku + puse_atstumo;

            for(int k = 0 ; k < Nz - 1; k++)
            {
                z_Points.push_back(a);
                y_Points.push_back(b);
                x_Points.push_back(k * atstumas_tarp_tasku + puse_atstumo);
            }
        }
    }

    for(int i = 0; i < x_Points.size(); i++)
    {
        cout << x_Points[i] << " " << y_Points[i] << " " << z_Points[i] << endl;
    }

    Number_Of_Points = x_Points.size();

    parts = 1;

    for(int i = 0; i < Number_Of_Points; i++)
    {
        Skirtingi_spinduliai.push_back(Radius);
        Daleliu_ID.push_back(0);
    }
}

