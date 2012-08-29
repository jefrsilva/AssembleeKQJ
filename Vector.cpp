#include "Vector.h"

Vector::Vector() {
  x = y = z = 0.0;
}

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
    this->z = 0.0;
}

Vector::Vector(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector::Vector(Vector a, Vector b) {
  this->x = b.x - a.x;
  this->y = b.y - a.y;
  this->z = b.z - a.z;
}

Vector::~Vector() {
  
}

double Vector::length() {
  return sqrt(x * x + y * y + z * z);
}

Vector Vector::normalize() {
  double l = length();
  Vector normalized = Vector(0.0, 0.0, 0.0);

  if (l >= EPSILON) {
    normalized = Vector(x / l, y / l, z / l);
  }

  return normalized;
}

Vector Vector::translate(Vector t) {
  return Vector(x + t.x, y + t.y, z + t.z);
}

double Vector::dot(Vector other) {
  return x * other.x + y * other.y + z * other.z;
}

Vector Vector::cross(Vector other) {
  Vector v;

  v.x = this->y * other.z - this->z * other.y;
  v.y = this->z * other.x - this->x * other.z;
  v.z = this->x * other.y - this->y * other.x;

  return v;
}

Vector Vector::mult(double s) {
  return Vector(x * s, y * s, z * s);
}

