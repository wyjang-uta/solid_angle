#include <iostream>
#include <vector>
#include <cmath>

struct Vec3 {
  double x, y, z;

  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

  Vec3 operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
  }

  Vec3 operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
  }

  Vec3 operator*(double scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
  }

  double length() const {
    return std::sqrt(x * x + y * y + z * z);
  }

  Vec3 normalize() const {
    double len = length();
    return Vec3(x / len, y / len, z / len);
  }

  double dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  Vec3 cross(const Vec3& other) const {
    return Vec3(y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x);
  }
};

struct Triangle {
  Vec3 a, b, c;

  Triangle(const Vec3& a, const Vec3& b, const Vec3& c) : a(a), b(b), c(c) {}

  Vec3 normal() const {
    return (b - a).cross(c - a).normalize();
  }

  double area() const {
    return 0.5 * (b - a).cross(c - a).length();
  }

  double solidAngle(const Vec3& ref) const {
    /*
       Vec3 n = normal();
       double cos_theta = n.dot(p) / (n.length() * p.length());
       return 2 * std::atan2(area(), a.length() * b.length() * c.length() + a.dot(b.cross(c))) * cos_theta * cos_theta;
       */

    // First, set reference point.
    Vec3 va(a.x - ref.x, a.y - ref.y, a.z - ref.z);
    Vec3 vb(b.x - ref.x, b.y - ref.y, b.z - ref.z);
    Vec3 vc(c.x - ref.x, c.y - ref.y, c.z - ref.z);
    // First, project each vertex of triangle onto a unit sphere.
    Vec3 pa(va.x/va.length(), va.y/va.length(), va.z/va.length());
    Vec3 pb(vb.x/vb.length(), vb.y/vb.length(), vb.z/vb.length());
    Vec3 pc(vc.x/vc.length(), vc.y/vc.length(), vc.z/vc.length());
    // Second, calculate the spherical area of projected triangle.
    double t = fabs( pa.dot(pb.cross(pc)) );
    t /= 1.0 + pa.dot(pb) + pb.dot(pc) + pc.dot(pa);
    return 2*atan(t);
  }

  void translation(const Vec3& v) const {
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

};

class Mesh {
  public:
    Mesh() {}

    void addTriangle(const Triangle& t) {
      triangles_.push_back(t);
    }

    void translation(const Vec3& v) const {
      for( const Triangle& t : triangles_ ) {
        t.translation(v);
      }
    }

    double solidAngle(const Vec3& p) const {
      double solid_angle = 0.0;
      for (const Triangle& t : triangles_) {
        solid_angle += t.solidAngle(p);
      }
      return solid_angle;
    }

  private:
    std::vector<Triangle> triangles_;
};

int main() {
  Mesh mesh;
  // Add triangles to the mesh, for example:
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, 1.0), Vec3(1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, 1.0), Vec3(1.0, 0.0, 0.0), Vec3(0.0, -1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, 1.0), Vec3(-1.0, 0.0, 0.0), Vec3(0.0, -1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, 1.0), Vec3(-1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, -1.0), Vec3(1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, -1.0), Vec3(1.0, 0.0, 0.0), Vec3(0.0, -1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, -1.0), Vec3(-1.0, 0.0, 0.0), Vec3(0.0, -1.0, 0.0)));
  mesh.addTriangle(Triangle(Vec3(0.0, 0.0, -1.0), Vec3(-1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0)));

  //mesh.addTriangle(Triangle(Vec3(1.0, 0.0, 0.0), Vec3(2.0, 0.0, 1.0), Vec3(1.0, 0.0, 0.0)));
  // Calculate the solid angle from the origin
  double solid_angle = mesh.solidAngle(Vec3(0.0, 0.0, 0.0));

  std::cout << "Solid angle from the origin: " << solid_angle << " steradians, and it is " << solid_angle/M_PI << " pi (sr)." << std::endl;
  std::cout << "1/8 * 4 * pi = " << M_PI/2.0 << std::endl;

  return 0;
}


