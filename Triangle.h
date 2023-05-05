#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector3.h"

struct Triangle {
  Vector3 a, b, c;

  Triangle( const Vector3& a, const Vector3& b, const Vector3& c ) : a(a), b(b), c(c) {}

  Vector3 GetNormalVector() const;
  double GetArea() const;
  double GetSolidAngle(const Vector3& ref) const;
  void Translation( const Vector3& v );

};
#endif

