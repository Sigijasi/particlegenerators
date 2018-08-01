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
    p->SetNumberOfPoints(Number_Of_Points);
    vtkDoubleArray *r = vtkDoubleArray::New();
    r->SetNumberOfComponents(1);
    r->SetName("RADIUS");
    r->SetNumberOfTuples(Number_Of_Points);
    vtkDoubleArray *id = vtkDoubleArray::New();
    id->SetNumberOfComponents(1);
    id->SetName("ID");
    id->SetNumberOfTuples(Number_Of_Points);
    vtkDoubleArray *Particle_type = vtkDoubleArray::New();
    Particle_type->SetNumberOfComponents(1);
    Particle_type->SetName("PARTICLE-TYPE");
    Particle_type->SetNumberOfTuples(Number_Of_Points);
    vtkDoubleArray *Particle_fix = vtkDoubleArray::New();
    Particle_fix->SetNumberOfComponents(1);
    Particle_fix->SetName("PARTICLE-FIX");
    Particle_fix->SetNumberOfTuples(Number_Of_Points);
    vtkDoubleArray *Particle_material = vtkDoubleArray::New();
    Particle_material->SetNumberOfComponents(1);
    Particle_material->SetName("PARTICLE-MATERIAL");
    Particle_material->SetNumberOfTuples(Number_Of_Points);
    vtkDoubleArray *Velocity = vtkDoubleArray::New();
    Velocity->SetNumberOfComponents(3);
    Velocity->SetName("VELOCITY");
    Velocity->SetNumberOfTuples(Number_Of_Points);
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
   double x, y, z, ilgis_2, paklaida(5e-16), x_1, y_1, z_1;

//------------------------------------------------------------------------------------------------------------

   if(parts == 1)
   {
       for(int i = 0; i < x_Points.size() ; i++)
       {
           x_1 = x_Points[i];
           y_1 = y_Points[i];
           z_1 = z_Points[i];

           for(int j = i + 1; j < x_Points.size(); j++)
           {
               x = x_Points[j] - x_1;
               y = y_Points[j] - y_1;
               z = z_Points[j] - z_1;

               ilgis_2 = ((2 * Radius) * (2 * Radius) * (2 * Radius) * (2 * Radius)) - (((x * x) + (y * y) + (z * z)) * ((x * x) + (y * y) + (z * z)));

               if(fabs(ilgis_2) < paklaida)
               {
                   cells->InsertNextCell(2);
                   cells->InsertCellPoint(i);
                   cells->InsertCellPoint(j);
                   ilgis->InsertNextTuple1(ilgis_2);
               }
           }
       }

       x_1 = 0;

       y_1 = 0;

       z_1 = 0;
   }



   else if(parts == 2)
   {
       for(int i = 0; i < pirma_dalis; i++)
       {
            x_1 = x_Points[i];
            y_1 = y_Points[i];
            z_1 = z_Points[i];
           for(int j = i + 1; j < pirma_dalis; j++)
           {
               x = x_Points[j] - x_1;
               y = y_Points[j] - y_1;
               z = z_Points[j] - z_1;

               ilgis_2 = ((2 * Radius) * (2 * Radius) * (2 * Radius) * (2 * Radius)) - (((x * x) + (y * y) + (z * z)) * ((x * x) + (y * y) + (z * z)));

               if(fabs(ilgis_2) < paklaida)
               {
                   cells->InsertNextCell(2);
                   cells->InsertCellPoint(i);
                   cells->InsertCellPoint(j);
                   ilgis->InsertNextTuple1(ilgis_2);
               }
           }
       }

       x_1 = 0;

       y_1 = 0;

       z_1 = 0;

       for(int i = 0; i < x_Points.size(); i++)
       {
           x_1 = x_Points[i];
           y_1 = y_Points[i];
           z_1 = z_Points[i];

           for(int j = i + 1; j < x_Points.size(); j++)
           {
               x = x_Points[j] - x_1;
               y = y_Points[j] - y_1;
               z = z_Points[j] - z_1;

               ilgis_2 = ((radiusHcube + Radius) * (radiusHcube + Radius) * (radiusHcube + Radius) * (radiusHcube + Radius)) -
               (((x * x) + (y * y) + (z * z)) * ((x * x) + (y * y) + (z * z)));

               if(fabs(ilgis_2) < paklaida || ilgis_2 == 0)
               {
                   cells->InsertNextCell(2);
                   cells->InsertCellPoint(i);
                   cells->InsertCellPoint(j);
                   ilgis->InsertNextTuple1(ilgis_2);
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
    writer->SetFileName("Test2.vtp");
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
