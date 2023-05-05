#include <cmath>

#include "Triangle.h"
#include "Vector3.h"

Vector3 Triangle::GetNormalVector() const {
    return (b - a).Cross(c - a).GetNormalVector();
}

double Triangle::GetArea() const {
  return 0.5 * ( b - a ).Cross( c - a ).GetLength();
}

double Triangle::GetSolidAngle( const Vector3& ref) const
{
    // First, set reference point.
    Vector3 va(a.x - ref.x, a.y - ref.y, a.z - ref.z);
    Vector3 vb(b.x - ref.x, b.y - ref.y, b.z - ref.z);
    Vector3 vc(c.x - ref.x, c.y - ref.y, c.z - ref.z);
    // First, project each vertex of triangle onto a unit sphere.
    /*
    Vector3 pa(va.x/va.length(), va.y/va.length(), va.z/va.length());
    Vector3 pb(vb.x/vb.length(), vb.y/vb.length(), vb.z/vb.length());
    Vector3 pc(vc.x/vc.length(), vc.y/vc.length(), vc.z/vc.length());
    */
    Vector3 pa = va.GetNormalVector();
    Vector3 pb = vb.GetNormalVector();
    Vector3 pc = vc.GetNormalVector();
    // Second, calculate the spherical area of projected triangle.
    double t = fabs( pa.Dot(pb.Cross(pc)) );
    t /= 1.0 + pa.Dot(pb) + pb.Dot(pc) + pc.Dot(pa);
    return 2*atan(t);
}

void Triangle::Translation( const Vector3& v )
{
    a.x += v.x;
    a.y += v.y;
    a.z += v.z;
    b.x += v.x;
    b.y += v.y;
    b.z += v.z;
    c.x += v.x;
    c.y += v.y;
    c.z += v.z;
}
