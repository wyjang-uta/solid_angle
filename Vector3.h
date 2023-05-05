#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3 {
  double x, y, z;

  Vector3(double x, double y, double z ) : x(x), y(y), z(z) {}

  Vector3 operator+(const Vector3& other) const;
  Vector3 operator-(const Vector3& other) const;
  Vector3 operator*(double scalar) const;
  bool operator!=(Vector3& other) const;
  Vector3& operator=(const Vector3& other);
  double GetLength() const;
  Vector3 GetNormalVector() const;
  double Dot(const Vector3& other) const;
  Vector3 Cross(const Vector3& other) const;
};

#endif

