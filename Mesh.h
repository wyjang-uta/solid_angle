#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"
#include "Vector3.h"

class Mesh {
  public:
    Mesh() {}

    void AddTriangle(const Triangle& t);
    void Translation(const Vector3& v);
    double GetSolidAngle(const Vector3& p) const;

  private:
    std::vector<Triangle> triangles_;
};

#endif

