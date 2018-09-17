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
    cell_size = 2 * R; //randamas daleles skersmuo.

    Radius = R; //priskiriamas spindulio dydis.

    Nx1 = x2 - x1;
    Ny1 = y2 - y1;
    Nz1 = z2 - z1;

    Nz = (z2 - z1) / cell_size;
    Ny = (y2 - y1) / cell_size; //randamas daleliu kiekis, kuris telpa i pasirinktose ribose.
    Nx = (x2 - x1) / cell_size;


}
 void Generator1::SaveToFileVTK()
 {
    vtkPoints *p = vtkPoints::New();
    p->SetNumberOfPoints(x_Points.size());

    vtkDoubleArray *r = vtkDoubleArray::New(); // sukuriamas VTK masyvas - r.
    r->SetNumberOfComponents(1);
    r->SetName("RADIUS");
    r->SetNumberOfTuples(x_Points.size());

    vtkDoubleArray *ID = vtkDoubleArray::New(); //sukuriamas VTK masyvas - ID.
    ID->SetNumberOfComponents(1);
    ID->SetName("ID");
    ID->SetNumberOfTuples(x_Points.size());

    vtkDoubleArray *Particle_type = vtkDoubleArray::New(); //sukuriamas VTK masyvas - Particle type.
    Particle_type->SetNumberOfComponents(1);
    Particle_type->SetName("PARTICLE-TYPE");
    Particle_type->SetNumberOfTuples(x_Points.size());

    vtkDoubleArray *Particle_fix = vtkDoubleArray::New(); //sukuriamas VTK masyvas - Particle fix.
    Particle_fix->SetNumberOfComponents(1);
    Particle_fix->SetName("PARTICLE-FIX");
    Particle_fix->SetNumberOfTuples(x_Points.size());

    vtkDoubleArray *Particle_material = vtkDoubleArray::New(); //sukuriamas VTK masyvas - Particle material.
    Particle_material->SetNumberOfComponents(1);
    Particle_material->SetName("PARTICLE-MATERIAL");
    Particle_material->SetNumberOfTuples(x_Points.size());

    vtkDoubleArray *Velocity = vtkDoubleArray::New(); //sukuriamas VTK masyvas - Velocity.
    Velocity->SetNumberOfComponents(3);
    Velocity->SetName("VELOCITY");
    Velocity->SetNumberOfTuples(x_Points.size());

    vtkDoubleArray *Unique_radius = vtkDoubleArray::New(); //sukuriamas VTK masyvas - Unique Radius.
    Unique_radius->SetNumberOfComponents(1);
    Unique_radius->SetName("UNIQUE-RADIUS");
    Unique_radius->SetNumberOfTuples(parts);

    vtkDoubleArray *Distance  = vtkDoubleArray::New(); //sukuriamas VTK masyvas - Distance.
    Distance->SetNumberOfComponents(1);
    Distance->SetName("DISTANCE");

    vtkCellArray *cells = vtkCellArray::New(); //sukuriamas VTK deleliu masyvas.

    for(int i = 0; i < x_Points.size(); i++) //talpinamos reiksmes i masyvus.
    {
        ID->SetTuple1(i, Daleliu_ID[i]);

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


       for(int i = 0; i < x_Points.size(); i++)
       {
           //randamos lasteliu koordinates (a, b, c).
           int Cell_Coordinate_X;
           Cell_Coordinate_X = x_Points[i] / cell_size;

           int Cell_Coordinate_Y;
           Cell_Coordinate_Y = y_Points[i] / cell_size;

           int  Cell_Coordinate_Z = 0;
           Cell_Coordinate_Z = z_Points[i] / cell_size;

           //skaiciuojama i kuria lastele patenka tam tikra dalele.
           int Cell_Position;
           Cell_Position = Cell_Coordinate_X + Cell_Coordinate_Y * Nx + Cell_Coordinate_Z * Nz * Ny;

           //talpinamas rezultate gautas lasteles id.
           L_array.push_back(Cell_Position);

           //kiekvienos daleles ID pridedamas i masyva.
           ID_array.push_back(i);
       }

       //Rusiavimas:
       vector<pair<int, int>> RusiuojamasVektorius;

       for(int i = 0; i < L_array.size(); i++)
       {
           //masyvu duomenys suskirstomi poromis.
           RusiuojamasVektorius.push_back(make_pair(L_array[i], ID_array[i]));
       }

       //L_array masyvas rusiuojamas didejimo tvarka, ID_array rusiuojamas pagal L_array.
       sort(RusiuojamasVektorius.begin(), RusiuojamasVektorius.end());

       for(int i = 0; i < L_array.size(); i++)
       {
           L_array[i] = RusiuojamasVektorius[i].first;
           ID_array[i] = RusiuojamasVektorius[i].second;
       }

       //lasteliu skaicius
       int lasteliuSkaicius = Nx * Ny * Nz;

       vector<int> start;
       vector<int> end;

       int Daleliu_Suma = 0;

       //ciklas eina per visas daleles nuo 0 iki n lasteles.
       for(int i = 0; i < lasteliuSkaicius; i++)
       {
           //daleliu skaicius lasteleje pradedamas skaicuoti nuo nulio.
           int DaleliuSkaiciusLasteleje = 0;

           //ciklo pagalba einama per L_array masyva.
           for(int j = 0; j < L_array.size(); j++)
           {
               //jei lasteles indeksas atitinka daleles lasteles indeksui patenkama i if'a.
               if(i == L_array[j] )
               {
                   //randamas daleliu skaicius tam tikroje lasteleje.
                   DaleliuSkaiciusLasteleje++;

                   if(i +1 <= L_array.size())
                   {
                       if(i < L_array[i + 1])
                       {
                           break;
                       }

                   }

               }


           }

           //sumuojama daleliu suma
           Daleliu_Suma += DaleliuSkaiciusLasteleje;

           //jei daleliu skaicius lasteleje != 0, i masyva talpinamos atitinkamos reiksmes.
           if(DaleliuSkaiciusLasteleje != 0)
           {
               start.push_back(Daleliu_Suma - DaleliuSkaiciusLasteleje);
               end.push_back(Daleliu_Suma - 1);
           }

           //jei daleliu skaicius lasteleje == 0, i masyva talpinamos -1 reiksmes
           else if(DaleliuSkaiciusLasteleje == 0)
           {
               start.push_back(-1);
               end.push_back(-1);
           }
       }


       for(int i = 0; i < start.size(); i++)
       {
           cout << start[i] << " " << end[i] << endl;
       }

       for(int p = 0; p < x_Points.size(); p++)
       {
           int i = 0, j = 0, k = 0;

           i = std::ceil(x_Points[p] / cell_size); //lasteles indeksas x asimi.

           j = std::ceil(y_Points[p] / cell_size); //lasteles indeksas y asimi.

           k = std::ceil(z_Points[p] / cell_size); //lasteles indeksas z asimi.

           for(int a = i - 2; a <= i + 2; a++) //tris ciklai apimantys visas esamas daleles.
           {
               for(int b = j - 2; b <= j + 2; b++)
               {
                   for(int c = k - 2; c <= k + 2; c++)
                   {
                       if(a < 0 || a >= Nx || b < 0 || c < 0 || b >= Ny || c >= Nz) //tikrinamos pasirinktu dydziu ribos tikrinant.
                       {
                           continue;
                       }

                       int ID = a + b * Nx + c * Nz * Ny;

                       int Start = start[ID], End = end[ID];

                       //ciklo pagalba tikrinamos visos daleles esancios vienoje lasteleje.
                       for(int u = Start; u <= End; u++)
                       {
                           double ilgis1 = 0;
                           ilgis1 = sqrt(pow((x_Points[p] - x_Points[ID_array[u]]), 2) + pow((y_Points[p] - y_Points[ID_array[u]]), 2) + pow((z_Points[p] - z_Points[ID_array[u]]), 2));

                           //randamas atstumu tarp daleliu skirtumas.
                           double paklaida = 0;
                           paklaida = fabs(ilgis1 - Skirtingi_spinduliai[ID_array[u]] - Skirtingi_spinduliai[p]);

                           //pasirinkta paklaidos reiksme.
                           double konst(8e-4);

                           //tikrinama ar tenkinama pasirinkta salyga.
                           if(paklaida <= konst)
                           {
                               cells->InsertNextCell(2);

                               cells->InsertCellPoint(p);

                               cells->InsertCellPoint(ID_array[u]);

                               Distance->InsertNextTuple1(ilgis1);
                           }
                       }
                   }
               }
           }
       }

   poly->SetLines(cells);
   poly->GetCellData()->SetScalars(Distance);
   poly->SetPoints(p);
   poly->GetPointData()->SetScalars(r);
   poly->GetPointData()->AddArray(Particle_fix);
   poly->GetPointData()->AddArray(ID);
   poly->GetPointData()->AddArray(Particle_type);
   poly->GetPointData()->AddArray(Particle_material);
   poly->GetFieldData()->AddArray(Unique_radius);

   vtkXMLPolyDataWriter *writer = vtkXMLPolyDataWriter::New();

   writer->SetInputData(poly);
   writer->SetFileName("new112555.vtp");
   writer->Write();
   writer->Delete();
   Unique_radius->Delete();
   Velocity->Delete();
   Particle_material->Delete();
   Particle_type->Delete();
   ID->Delete();
   r->Delete();
   p->Delete();
   poly->Delete();
}
