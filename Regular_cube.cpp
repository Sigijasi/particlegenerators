#include "Regular_cube.h"
#include "Generator1.h"
#include <iostream>
#include <cstdio>

using namespace std;

Regular_cube::Regular_cube()
{
}

Regular_cube::~Regular_cube()
{
}

void Regular_cube::Generate()
{
    //triju ciklu pagalba ieskomos kiekvienos daleles koordinates (x, y, z).
    for(int i = 0; i < Nx; i++)
    {
        long double a = 0;
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
                y_Points.push_back(b);//sudaromi trys daleliu koordinaciu masyvai: X koordinates - x_Points, Y - y_Points, Z - z_Points.
                z_Points.push_back(c);
            }
        }
    }

    for(int i = 0; i < x_Points.size(); i++)
    {
        Skirtingi_spinduliai.push_back(Radius); //spindulys priskiriamas kiekvienai dalelei.
        Daleliu_ID.push_back(0); //kiekvienai dalelei priskiriamas spindulio id.
    }
    parts = 1;
}

