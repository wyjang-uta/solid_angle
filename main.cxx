#include <iostream>
#include <vector>
#include <cmath>
#include "Mesh.h"
#include "Triangle.h"
#include "Vector3.h"

int main() {
  Mesh mesh;
  // Add triangles to the mesh, for example:
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, 1.0), Vector3(1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, 1.0), Vector3(1.0, 0.0, 0.0), Vector3(0.0, -1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, 1.0), Vector3(-1.0, 0.0, 0.0), Vector3(0.0, -1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, 1.0), Vector3(-1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, -1.0), Vector3(1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, -1.0), Vector3(1.0, 0.0, 0.0), Vector3(0.0, -1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, -1.0), Vector3(-1.0, 0.0, 0.0), Vector3(0.0, -1.0, 0.0)));
  mesh.AddTriangle(Triangle(Vector3(0.0, 0.0, -1.0), Vector3(-1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0)));

  //mesh.AddTriangle(Triangle(Vector3(1.0, 0.0, 0.0), Vector3(2.0, 0.0, 1.0), Vector3(1.0, 0.0, 0.0)));
  // Calculate the solid angle from the origin
  double solid_angle = mesh.GetSolidAngle(Vector3(0.0, 0.0, 0.0));

  std::cout << "Solid angle from the origin: " << solid_angle << " steradians, and it is " << solid_angle/M_PI << " pi (sr)." << std::endl;
  std::cout << "1/8 * 4 * pi = " << M_PI/2.0 << std::endl;

  return 0;
}


