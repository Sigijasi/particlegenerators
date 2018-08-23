#include "Generator1.h"

#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkDoubleArray.h>
#include <vtkCellArray.h>
#include <vtkDataSetWriter.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkFieldData.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkVersion.h>
#include <vtkPolyData.h>
#include <vtkLine.h>
#include <vtkPolyLine.h>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vtkXMLPolyDataWriter.h>
#include <cmath>
#include <algorithm>

using namespace std;
Generator1::Generator1()
{
    poly = vtkPolyData::New();
}
Generator1::~Generator1()
{
}

void Generator1::initGrid(double R, double x1, double x2, double y1, double y2, double z1, double z2)
{
    cell_size = 2 * R;
    Radius = R;
    Nx1 = x2 - x1;
    Ny1 = y2 - y1;
    Nz1 = z2 - z1;
    Nz = (z2 - z1) / cell_size;
    Ny = (y2 - y1) / cell_size;
    Nx = (x2 - x1) / cell_size;
}
 void Generator1::SaveToFileVTK()
 {
    vtkPoints *p = vtkPoints::New();
    p->SetNumberOfPoints(x_Points.size());
    vtkDoubleArray *r = vtkDoubleArray::New();
    r->SetNumberOfComponents(1);
    r->SetName("RADIUS");
    r->SetNumberOfTuples(x_Points.size());
    vtkDoubleArray *id = vtkDoubleArray::New();
    id->SetNumberOfComponents(1);
    id->SetName("ID");
    id->SetNumberOfTuples(x_Points.size());
    vtkDoubleArray *Particle_type = vtkDoubleArray::New();
    Particle_type->SetNumberOfComponents(1);
    Particle_type->SetName("PARTICLE-TYPE");
    Particle_type->SetNumberOfTuples(x_Points.size());
    vtkDoubleArray *Particle_fix = vtkDoubleArray::New();
    Particle_fix->SetNumberOfComponents(1);
    Particle_fix->SetName("PARTICLE-FIX");
    Particle_fix->SetNumberOfTuples(x_Points.size());
    vtkDoubleArray *Particle_material = vtkDoubleArray::New();
    Particle_material->SetNumberOfComponents(1);
    Particle_material->SetName("PARTICLE-MATERIAL");
    Particle_material->SetNumberOfTuples(x_Points.size());
    vtkDoubleArray *Velocity = vtkDoubleArray::New();
    Velocity->SetNumberOfComponents(3);
    Velocity->SetName("VELOCITY");
    Velocity->SetNumberOfTuples(x_Points.size());
    vtkDoubleArray *Unique_radius = vtkDoubleArray::New();
    Unique_radius->SetNumberOfComponents(1);
    Unique_radius->SetName("UNIQUE-RADIUS");
    Unique_radius->SetNumberOfTuples(parts);
    vtkDoubleArray *ilgis  = vtkDoubleArray::New();
    ilgis->SetNumberOfComponents(1);
    ilgis->SetName("DISTANCE");

    vtkCellArray *cells = vtkCellArray::New();

    for(int i = 0; i < x_Points.size(); i++)
    {
        id->SetTuple1(i, Daleliu_ID[i]);
        Particle_type->SetTuple1(i, 0);
        Particle_material->SetTuple1(i, 0);
        Particle_fix->SetTuple1(i, 0);
        Velocity->SetTuple3(i, 0, 0, 0);
        r->SetTuple1(i, Skirtingi_spinduliai[i]);
        p->SetPoint(i, x_Points[i], y_Points[i], z_Points[i]);
    }

    if(temp == 0)
    {
         Unique_radius->SetTuple1(1, Radius);
    }

    else if(temp == 1)
    {
        for(int i = 0; i < parts; i++)
        {
            Unique_radius->SetTuple1(i, Random_radius[i]);
        }
    }

//------------------------------------------------------------------------------------------------------------

   if(parts == 1)
   {

       int a = 0, b = 0, c = 0, FormulesRezultatas;
       int Daleles_ID = -1;

       for(int i = 0; i < x_Points.size(); i++)
       {
           a = x_Points[i] / cell_size;
           b = y_Points[i] / cell_size;
           c = z_Points[i] / cell_size;

           FormulesRezultatas = a + b * Nx + c * Nx * Ny;

           L_array.push_back(FormulesRezultatas);
           Daleles_ID++;
           ID_array.push_back(Daleles_ID);
       }

       vector<pair<int, int>> RusiuojamasVektorius;

       for(int i = 0; i < L_array.size(); i++)
       {
           RusiuojamasVektorius.push_back(make_pair(L_array[i], ID_array[i]));
       }

       sort(RusiuojamasVektorius.begin(), RusiuojamasVektorius.end());

       for(int i = 0; i < L_array.size() + 1; i++)
       {
           L_array[i] = RusiuojamasVektorius[i].first;
           ID_array[i] = RusiuojamasVektorius[i].second;
       }

       L_array.push_back(0);

       ID_array.push_back(0);

       std::vector<int> START;
       std::vector<int> END;

       START.push_back(0);

       int counter = 0, counter1 = 1;

       for(int i = 0; i < L_array.size() - 1; i++)
       {
           counter++;

           if(L_array[i] == L_array[i + 1])
           {
               counter1++;
           }

           else if(L_array[i] <= L_array[i + 1])
           {
               END.push_back(counter - 1);
               START.push_back(counter);
           }

           else if(L_array[i + 1] == 0)
           {
               END.push_back(counter - 1);
           }
       }

       for(int i = 0; i < START.size(); i++)
       {
           cout << START.at(i) << " " << END.at(i) << endl;
       }

       int i = 0, j = 0, k = 0, ID = 0, S = 0, C = 0, d;
       double rx1 = 0, ry1 = 0, rz1 = 0, rx2 = 0, ry2 = 0, rz2 = 0, ilgis1 = 0;

       for(int p = 0; p < x_Points.size(); p++)
       {
           i = std::ceil(x_Points[p] / cell_size);  ///celes indexkas X asinui

           rx1 = x_Points[p];


           j = std::ceil(y_Points[p] / cell_size);

           ry1 = y_Points[p];


           k = std::ceil(z_Points[p] / cell_size);

           rz1 = z_Points[p];

           //sities trus cuikklai apeima 27 celes343

           for(int a = i - 1; a <= i + 1; a++)
           {
               for(int b = j - 1; b <= j + 1; b++)
               {
                   for(int c = k - 1; c <= k + 1; c++)
                   {
                       if(a < 0 || a >= Nx || b < 0 || c < 0 || b >= Ny || c >= Nz) //tikrinamos ribos
                       {
                           continue;
                       }

                       ID = a + b * Nx + c * Nx * Ny;

                       S = START[ID];

                       C = END[ID];

                       for(int u = S; u <= C; u++)
                       {
                           d = ID_array[u];
                           rx2 = x_Points[d];
                           ry2 = y_Points[d];
                           rz2 = z_Points[d];

                           ilgis1 = sqrt(pow((rx1 - rx2), 2) + pow((ry1 - ry2), 2) + pow((rz1 - rz2), 2));

                           double paklaida_ = 0, kkk(8e-6);

                           paklaida_ = fabs(ilgis1 - Skirtingi_spinduliai[d] - Skirtingi_spinduliai[p]);

                           if(paklaida_ <= kkk)
                           {
                               cells->InsertNextCell(2);
                               cells->InsertCellPoint(p);
                               cells->InsertCellPoint(d);
                               ilgis->InsertNextTuple1(ilgis1);
                           }
                       }
                   }
               }
           }
       }
   }

   poly->SetLines(cells);
   poly->GetCellData()->SetScalars(ilgis);
   poly->SetPoints(p);
   poly->GetPointData()->SetScalars(r);
   poly->GetPointData()->AddArray(Particle_fix);
   poly->GetPointData()->AddArray(id);
   poly->GetPointData()->AddArray(Particle_type);
   poly->GetPointData()->AddArray(Particle_material);
   poly->GetFieldData()->AddArray(Unique_radius);

   vtkXMLPolyDataWriter *writer = vtkXMLPolyDataWriter::New();

   writer->SetInputData(poly);
   writer->SetFileName("Redagavimas.vtp");
   writer->Write();
   writer->Delete();
   Unique_radius->Delete();
   Velocity->Delete();
   Particle_material->Delete();
   Particle_type->Delete();
   id->Delete();
   r->Delete();
   p->Delete();
   poly->Delete();
}




