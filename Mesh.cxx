#include "Mesh.h"

void Mesh::AddTriangle(const Triangle& t)
{
  triangles_.push_back(t);
}

void Mesh::Translation(const Vector3& v)
{
  // for( const Triangle& t : triangles_ ) {
  //   This line will make an error:
  //    error: passing ‘const Triangle’ as ‘this’ argument discards qualifiers [-fpermissive]
  // The reason why we have this error is that we declared Triangle& t as a constant instant but
  // the function Triangle::Translation() actually attempt to change the content of Triangle instance
  // therefore it violates the constant rule.
  //
  for( Triangle& t : triangles_ ) {
    t.Translation(v);
  }
}

double Mesh::GetSolidAngle(const Vector3& p) const
{
  double solid_angle = 0.0;
  for( const Triangle& t : triangles_ ) {
    solid_angle += t.GetSolidAngle(p);
  }
  return solid_angle;
}
