#include <iostream>
#include <fstream>
#include <vtkSphereSource.h>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkGlyph3D.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
using namespace std;
int main() {

    double d, aukstis, R, ilgis, plotis, x1(0), y1(0), x2(0), y2(0);
    int count(0), sandauga, telpaaukstis, telpailgis;

    cout << "Ivesti: (x2, y2, z2) ir daleles spinduli: ";
    cin >> ilgis >> aukstis >> plotis >> R;
    telpailgis = ilgis / (2 * R);
    telpaaukstis = aukstis /(2 * R);
    sandauga = telpaaukstis * telpailgis;
    d=R+R;

    // Create a sphere
    vtkSmartPointer<vtkPoints> points =
      vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkDoubleArray> rr =
      vtkSmartPointer<vtkDoubleArray>::New();

    for(double j = R; j <= aukstis; j = j + d){
        if(j <= aukstis){
           for(double i = R; i <= ilgis; i = i + d){
              if(i <= ilgis){
                  for(double z = R; z <= plotis; z = z + d){
                    if(z <= plotis){
                        count++;
                        points->InsertNextPoint(i,j,z);
                        rr->InsertNextTuple1(R);
                    }
                 }
              }
           }
        }
     }

    vtkSmartPointer<vtkPolyData> polydata =
      vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);
    polydata->GetPointData()->SetScalars(rr);
    vtkSmartPointer<vtkPolyData> glyph =
      vtkSmartPointer<vtkPolyData>::New();

    // Create anything you want here, we will use a cube for the demo.
    vtkSmartPointer<vtkSphereSource> cubeSource =
        vtkSmartPointer<vtkSphereSource>::New();
    cubeSource->SetRadius(1);
    vtkSmartPointer<vtkGlyph3D> glyph3D =
      vtkSmartPointer<vtkGlyph3D>::New();
glyph3D->SetScaleModeToScaleByScalar();
glyph3D->SetScaleFactor(1);
    glyph3D->SetSourceConnection(cubeSource->GetOutputPort());
    glyph3D->SetInputData(polydata);

    glyph3D->Update();

    // Visualize
    vtkSmartPointer<vtkPolyDataMapper> mapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(glyph3D->GetOutputPort());

    vtkSmartPointer<vtkActor> actor =
      vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow =
      vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    renderer->AddActor(actor);
    renderer->SetBackground(.3, .6, .3); // Background color green

    renderWindow->Render();
    renderWindowInteractor->Start();
    return 0;
}

