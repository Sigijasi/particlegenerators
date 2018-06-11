#include "R_Cube.h"
#include "Generator1.h"
#include <iostream>
#include <random>

using namespace std;

R_Cube::R_Cube(double minimum, double maximum, int dalys)
{
    parts = dalys;
    r_min = minimum;
    r_max = maximum;
}
R_Cube::~R_Cube()
{   
}

void R_Cube::Generate()
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


    Number_Of_Points = (Nx * Ny) * Nz;

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(r_min, r_max);


    for(int n = 0; n < parts; n++)
    {
        Random_radius.push_back(distr(eng));
    }


    for(int i = 0; i < Number_Of_Points; i++)
    {
        v2 = rand() % parts   + 0;

        Skirtingi_spinduliai.push_back(Random_radius[v2]);

        Daleliu_ID.push_back(v2);

    }





}
