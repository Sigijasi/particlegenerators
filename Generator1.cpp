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
#include <iostream>

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
    r->SetName("Radius - (Spindulys)");
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

    Number_Of_Lines = Number_Of_Points;

    for(int i = 0; i < Number_Of_Points; i++)
    {
        id->SetTuple1(i, Daleliu_ID[i]);

        Particle_type->SetTuple1(i, 0);

        Particle_material->SetTuple1(i, 0);

        Particle_fix->SetTuple1(i, 0);

        Velocity->SetTuple3(i, 0, 0, 0);

        r->SetTuple1(i, Skirtingi_spinduliai[i]);
    }

    for(int i = 0; i < parts; i++)
    {
        Unique_radius->SetTuple1(i, Random_radius[i]);
    }

    for(int f = 0; f < x_Points.size(); f++) 
    {
        p->SetPoint(f, x_Points[f], y_Points[f], z_Points[f]);
    }

    poly->SetPoints(p);

    poly->GetPointData()->SetScalars(r);

    poly->GetPointData()->AddArray(Particle_fix);

    poly->GetPointData()->AddArray(id);

    poly->GetPointData()->AddArray(Particle_type);

    poly->GetPointData()->AddArray(Particle_material);

    poly->GetFieldData()->AddArray(Unique_radius);

    vtkDataSetWriter *writer = vtkDataSetWriter::New(); //Save_To_File_VTK. (voidas)

    writer->SetInputData(poly);

    writer->SetFileName("failas.vtk");

    writer->SetFileTypeToBinary();

    writer->Write();

    //-------------------

    writer->Delete();

    Unique_radius->Delete(); //istrynus visus issaugoo0t.

    Velocity->Delete();

    Particle_material->Delete();

    Particle_type->Delete();

    id->Delete();

    r->Delete();

    p->Delete();

    poly->Delete();

 }
