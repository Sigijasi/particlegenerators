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


  if(parts == 1)
  {
       for(int i = 0; i < x_Points.size(); i++)
       {
           int a = 0, b = 0, c = 0;
           a = x_Points[i] / cell_size;
           b = y_Points[i] / cell_size; //randamos lasteliu koordinates (a, b, c).
           c = z_Points[i] / cell_size;

           int FormulesRezultatas = 0;
           FormulesRezultatas = a + b * Nx + c * Nz * Ny; //skaiciuojama i kuria lastele patenka tam tikra dalele.

           L_array.push_back(FormulesRezultatas); //talpinamas rezultate gautas lasteles id.

           ID_array.push_back(i); //kiekvienos daleles ID pridedamas i masyva.
       }

       vector<pair<int, int>> RusiuojamasVektorius;

       for(int i = 0; i < L_array.size(); i++)
       {
           RusiuojamasVektorius.push_back(make_pair(L_array[i], ID_array[i])); //masyvu duomenys suskirstomi poromis.
       }

       sort(RusiuojamasVektorius.begin(), RusiuojamasVektorius.end()); //L_array masyvas rusiuojamas didejimo tvarka, ID_array rusiuojamas pagal L_array.

       for(int i = 0; i < L_array.size(); i++)
       {
           L_array[i] = RusiuojamasVektorius[i].first;
           ID_array[i] = RusiuojamasVektorius[i].second;
       }


       int lasteliuSkaicius = Nx * Ny * Nz;






       cout << endl;

       //==================================================================


       std::vector<int> gridCOUNT;



       for(int i = 0; i < lasteliuSkaicius; i++)
       {
           gridCOUNT.push_back(0);
       }

       for(int i = 0; i < L_array.size(); i++)
       {
           int a1 = 0;
           a1 = gridCOUNT[L_array[i]] + 1;

           gridCOUNT[L_array[i]] = 0;

           gridCOUNT[L_array[i]] = a1;

       }

       for(int i = 0; i < lasteliuSkaicius; i++)
       {
           cout << gridCOUNT[i] << endl;
       }

cout << endl;

       //========================================================================


       std::vector<int> START;
       std::vector<int> END;

        START.push_back(0);
       for(int i = 0; i < lasteliuSkaicius; i++)
       {

           if(gridCOUNT[i] == 2)
           {
               END.push_back(i + gridCOUNT[i]);
               START.push_back(gridCOUNT[i + 1]);
           }
           else
           {


           END.push_back(i + gridCOUNT[i]);
           START.push_back(i + 1);
           }

       }

int suma;
       for (int i = 0; i < lasteliuSkaicius; i++)
       {
           suma+=gridCOUNT[i];
          cout << START[i] << " - " << END[i] << "             " << gridCOUNT.at(i) << endl;
       }




       for(int p = 0; p < x_Points.size(); p++)
       {
           int i = 0, j = 0, k = 0;

           i = std::ceil(x_Points[p] / cell_size); //lasteles indeksas x asimi.

           j = std::ceil(y_Points[p] / cell_size); //lasteles indeksas y asimi.

           k = std::ceil(z_Points[p] / cell_size); //lasteles indeksas z asimi.

           for(int a = i - 1; a <= i + 1; a++) //tris ciklai apimantys visas esamas daleles.
           {
               for(int b = j - 1; b <= j + 1; b++)
               {
                   for(int c = k - 1; c <= k + 1; c++)
                   {
                       if(a < 0 || a >= Nx || b < 0 || c < 0 || b >= Ny || c >= Nz) //tikrinamos pasirinktu dydziu ribos tikrinant.
                       {
                           continue;
                       }

                       int ID = a + b * Nx + c * Nz * Ny;

                       int Start = START[ID], End = END[ID];

                       for(int u = Start; u < End; u++) //ciklo pagalba tikrinamos visos daleles esancios vienoje lasteleje.
                       {
                           double ilgis1 = 0;
                           ilgis1 = sqrt(pow((x_Points[p] - x_Points[ID_array[u]]), 2) + pow((y_Points[p] - y_Points[ID_array[u]]), 2) + pow((z_Points[p] - z_Points[ID_array[u]]), 2));

                           double paklaida = 0;
                           paklaida = fabs(ilgis1 - Skirtingi_spinduliai[ID_array[u]] - Skirtingi_spinduliai[p]); //randamas atstumu tarp daleliu skirtumas,.

                           double konst(8e-6); //pasirinkta paklaidos reiksme.

                           if(paklaida <= konst) //tikrinama ar tenkinama pasirinkta salyga.
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
   writer->SetFileName("test100.vtp");
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
