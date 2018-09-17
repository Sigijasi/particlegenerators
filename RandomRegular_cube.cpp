#include "Random_Hexagonal_cube.h"
#include "Generator1.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

Random_Hexagonal_cube::Random_Hexagonal_cube(double minimum, double maximum, int dalys)
{
    parts = dalys;   //skirtingu spinduliu skaicius, kuris bus naudojamas generuojant - Random_Hexagonal_cube
    r_min = minimum; //minimali spindulio reiksme.
    r_max = maximum; //maksimali sindulio reiksme.
}

Random_Hexagonal_cube::~Random_Hexagonal_cube()
{
}

void Random_Hexagonal_cube::Generate()
{
    for(int i = 0; i < Nx; i++) //triju ciklu pagalba ieskomos kiekvienos daleles koordinates (x, y, z).
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
                y_Points.push_back(b); //sudaromi trys daleliu koordinaciu masyvai: X koordinates - x_Points, Y - y_Points, Z - z_Points.
                z_Points.push_back(c);
            }
        }
    }

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(r_min, r_max);

    for(int n = 0; n < parts; n++)
    {
        Random_radius.push_back(distr(eng)); //sugeneruotos skirtingu spinduliu reiksmes talpinamos i masyva.
    }

    for(int i = 0; i < x_Points.size(); i++)
    {
        int v2;
        v2 = rand() % parts + 0; //generuojamas skaicius, kurio pagalba bys pasirinkta random radius reiksme.

        Skirtingi_spinduliai.push_back(Random_radius[v2]); //pasirinktas random spindulys priskiriamas kiekvienai sugeneruotai dalelei.

        Daleliu_ID.push_back(v2); //kiekvienai dalelei priskiriamas id rementis spindulio dydziu.
    }

    temp = 1;
}
