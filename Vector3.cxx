#include <cmath>

#include "Vector3.h"

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
  return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(double scalar) const {
  return Vector3(x * scalar, y * scalar, z * scalar);
}

bool Vector3::operator!=(Vector3& other) const {
  return this != &other;
}

Vector3& Vector3::operator=(const Vector3& other) {
  if( this != &other )
  {
    x = other.x;
    y = other.y;
    z = other.z;
  }
  return *this;
}

double Vector3::GetLength() const {
  return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::GetNormalVector() const {
  double len = GetLength();
  return Vector3(x / len, y / len, z / len);
}

double Vector3::Dot(const Vector3& other) const {
  return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const {
  return Vector3(y * other.z - z * other.y,
      z * other.x - x * other.z,
      x * other.y - y * other.x);
}
