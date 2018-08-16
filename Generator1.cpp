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
        //cout << x_Points[i] << " - " << y_Points[i] << " - " << z_Points[i] << endl;

    }

    //cout << Random_radius.size() << endl;

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

   double x, y, z, ilgis_2, paklaida(5e-16), x_1, y_1, z_1;

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

       cout << "Soerted by first array:  L_array size: " << L_array.size() << " ID_array size: " << ID_array.size() << endl;


   L_array.push_back(0);

   for(int i = 0; i < L_array.size(); i++)
   {
       //cout << i << " = " << L_array[i] << " " << ID_array[i] << endl;
   }


   cout << "START - END(COUNT)" << endl;

   int Nx_Ny_Nz = Nx * Ny * Nz;

   std::vector<int> START;

   std::vector<int> COUNT_END;

   START.push_back(0);

   int counter = 0, counter1 = 1;

   for(int i = 0; i < L_array.size(); i++)
   {
       counter++;

       if(L_array[i] == L_array[i + 1])
       {
               counter1++;
       }

       else if(L_array[i] <= L_array[i + 1])
       {
           COUNT_END.push_back(counter - 1);

           START.push_back(counter);
       }

       else if(L_array[i + 1] == 0)
       {
               COUNT_END.push_back(counter - 1);
       }

   }

   cout << START.size() << " = " << Nx_Ny_Nz << endl;

   for(int i = 0; i < START.size(); i++)
   {
     cout << START[i] << " ---- " << COUNT_END[i] << endl;
   }

   //cout << "-----------------------------------------" << endl;

   int i = 0, j = 0, k = 0, ID = 0, S = 0, C = 0, daleliu_kiekis, d;

   double rx1 = 0, ry1 = 0, rz1 = 0, rx2 = 0, ry2 = 0, rz2 = 0, ilgis1 = 0;

   for(int p = 0; p < x_Points.size(); p++)
   {
           i = x_Points[p] / cell_size;
           rx1 = x_Points[p];

           j = y_Points[p] / cell_size;
           ry1 = y_Points[p];

           k = z_Points[p] / cell_size;
           rz1 = z_Points[p];

               for(int a = i - 1; a <= i + 1; a++)
               {
                   for(int b = j - 1; b <= j + 1; b++)
                   {
                       for(int c = k - 1; c <= k + 1; c++)
                       {
                           if(a < 0 || a >= Nx || b < 0 || c < 0 || b >= Ny || c >= Nz)
                           {
                               break;
                           }

                           ID = a + b * Nx + c * Nx * Ny;

                           S = START[ID];

                           C = COUNT_END[ID];

                           daleliu_kiekis = (C - S) + 1;

                           cout << daleliu_kiekis << endl;

                           for(int u = S; u <= C; u++)
                           {
                               d = ID_array[u];

                               rx2 = x_Points[d];
                               ry2 = y_Points[d];
                               rz2 = z_Points[d];



                               ilgis1 = sqrt(pow((rx1 - rx2), 2) + pow((ry1 - ry2), 2) + pow((rz1 - rz2), 2));

                               double paklaida_ = 0, kkk(8e-10);


                               paklaida_ = fabs(ilgis1 - Skirtingi_spinduliai[d] - Skirtingi_spinduliai[p]);

                               //cout << paklaida_ << endl;
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
    writer->SetFileName("test645564654.vtp");
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

 void Generator1::UniformGrid()
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
     for(int i = 0; i < ID_array.size(); i++)
     {
     cout << ID_array[i] << endl;
     }



     vector<pair<int, int>> vect;

     for(int i = 0; i < L_array.size(); i++)
     {
         vect.push_back(make_pair(L_array[i], ID_array[i]));
     }

     sort(vect.begin(), vect.end());

     cout << "Vektoriai po surusiavimo pagal pirmaji: " << endl;

     for(int i = 0; i < L_array.size() + 1; i++)
     {
         L_array[i] = vect[i].first;
         ID_array[i] = vect[i].second;
     }

     L_array.push_back(0);

     for(int i = 0; i < L_array.size(); i++)
     {
         //cout << i << " = " << L_array[i] << " " << ID_array[i] << endl;
     }


     cout << "START - END(COUNT)" << endl;

     int Nx_Ny_Nz = Nx * Ny * Nz;

     std::vector<int> START;

     std::vector<int> COUNT_END;

     std::vector<double> vektorius;

     START.push_back(0);

     int counter = 0, counter1 = 1;

     for(int i = 0; i < L_array.size(); i++)
     {
         counter++;

         if(L_array[i] == L_array[i + 1])
         {
                 counter1++;
         }

         else if(L_array[i] <= L_array[i + 1])
         {
             COUNT_END.push_back(counter - 1);

             START.push_back(counter);
         }

         else if(L_array[i + 1] == 0)
         {
                 COUNT_END.push_back(counter - 1);
         }

     }

     cout << START.size() << " = " << Nx_Ny_Nz << endl;

     //for(int i = 0; i < START.size(); i++)
     //{
       // cout << START[i] << " ---- " << COUNT_END[i] << endl;
     //}

     //cout << "-----------------------------------------" << endl;

     int i = 0, j = 0, k = 0, ID = 0, S = 0, C = 0, daleliu_kiekis, daleles_id;

     double rx1 = 0, ry1 = 0, rz1 = 0, rx2 = 0, ry2 = 0, rz2 = 0, ilgis = 0;

     for(int pp = 0; pp < x_Points.size(); pp++)
     {
             i = x_Points[pp] / cell_size;
             rx1 = x_Points[pp];

             j = y_Points[pp] / cell_size;
             ry1 = y_Points[pp];

             k = z_Points[pp] / cell_size;
             rz1 = z_Points[pp];

                 for(int a = i - 1; a <= i + 1; a++)
                 {
                     for(int b = j - 1; b < j + 1; b++)
                     {
                         for(int c = k - 1; c <= k + 1; c++)
                         {
                             if(a < 0 || a >= Nx || b < 0 || c < 0 || b >= Ny || c >= Nz)
                             {
                                 break;
                             }

                             ID = a + b * Nx + c * Nx * Ny;

                             S = START[ID];

                             C = COUNT_END[ID];

                             daleliu_kiekis = (C - S) + 1;

                             //cout << daleliu_kiekis << endl;

                             for(int u = S; u <= C; u++)
                             {
                                 daleles_id = ID_array[u];

                                 rx2 = x_Points[daleles_id];
                                 ry2 = y_Points[daleles_id];
                                 rz2 = z_Points[daleles_id];

                                 ilgis = sqrt(pow((rx1 - rx2), 2) + pow((ry1 - ry2), 2) + pow((rz1 - rz2), 2));

                                 double paklaida_ = 0, kkk(8e-10);


                                 paklaida_ = fabs(ilgis - Skirtingi_spinduliai[daleles_id] - Skirtingi_spinduliai[pp]);

                                 //cout << paklaida_ << endl;
                                 if(paklaida_ <= kkk)
                                 {
                                    vektorius.push_back(ilgis);
                                 }
                         }
                     }
                 }
                 }
     }



 }
