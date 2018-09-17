#include "test.h"
#include "Generator1.h"
#include <iostream>
#include <cstdio>

using namespace std;

test::test()
{
}

test::~test()
{
}

void test::Generate()
{
    double atstumas_tarp_tasku;

    atstumas_tarp_tasku = (Radius - (sqrt((Radius * Radius) / 2))) * 2;

    cout << atstumas_tarp_tasku << endl;

    cout << Nx << " " << Ny << " " << Nz << endl;
    for(int i = 0; i < Nx; i++)
    {
        long double a;
        a = (i * cell_size) + Radius;

        for(int j = 0; j < Ny; j++)
        {
            long double b;
            b = (j * cell_size) + Radius;

            for(int k = 0; k < Nz; k++)
            {
                long double c;
                c = (k * cell_size) + Radius;

                if(i == 0 || i % 2 == 0 && j == 0 || j % 2 == 0 && k == 0 || k % 2 == 0)
                {


                    x_Points.push_back(a);
                    y_Points.push_back(b);
                    z_Points.push_back(c);

                }
                else if(i != 0 || i % 2 != 0)
                {



                }
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
