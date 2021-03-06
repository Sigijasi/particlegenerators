#pragma once
#include <vector>
#include <vtkPolyData.h>

class Generator1
{

public:
    Generator1();
    ~Generator1();

    void initGrid(double R, double x1, double x2, double y1, double y2, double z1, double z2);

    void SaveToFileVTK();

    void UniformGrid();

    virtual void Generate() = 0;

    double x1, x2, y1, y2, z1, z2;
    double R , Radius;
    double cell_size;
    int Nx, Ny, Nz, Nx1, Ny1, Nz1;
    double parts;

    int temp = 0;

    double radiusHcube;

    vtkPolyData  *poly;

    std::vector<double> x_Points;
    std::vector<double> y_Points;
    std::vector<double> z_Points;

    std::vector<int> L_array;
    std::vector<int> ID_array;

    std::vector<double> Random_radius;
    std::vector<double> Skirtingi_spinduliai;
    std::vector<double> Daleliu_ID;
    int Number_Of_Points;

    int pirma_dalis = 0;
};
