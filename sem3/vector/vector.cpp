#include "Vector.h"

#include <iostream>
#include <cmath>

Vector::Vector() : x_start(0.0), y_start(0.0), z_start(0.0), x_end(0.0), y_end(0.0), z_end(0.0) {}

Vector::Vector(double x_start, double y_start, double z_start, double x_end, double y_end, double z_end)
    : x_start(x_start), y_start(y_start), z_start(z_start), x_end(x_end), y_end(y_end), z_end(z_end) {}

double Vector::length() const {
    double dx = x_end - x_start;
    double dy = y_end - y_start;
    double dz = z_end - z_start;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Vector Vector::operator +(const Vector& other) {
    return Vector(x_start, y_start, z_start,
        x_end + other.x_end - other.x_start, y_end + other.y_end - other.y_start, z_end + other.z_end - other.z_start);
}

void Vector::operator +=(Vector& other) {
    this->x_end += (other.x_end - other.x_start);
    this->y_end += (other.y_end - other.y_start);
    this->z_end += (other.z_end - other.z_start);
}

Vector Vector::operator -(const Vector& other) {
    return Vector(x_start, y_start, z_start,
        x_end - other.x_end + other.x_start, y_end - other.y_end + other.y_start, z_end - other.z_end + other.z_start);
}

void Vector::operator -=(Vector& other) {
    x_end -= other.x_end - other.x_start;
    y_end -= other.y_end - other.y_start;
    z_end -= other.z_end - other.z_start;
}

Vector Vector::operator *(const Vector& other) {
    double tdx = x_end - x_start;
    double tdy = y_end - y_start;
    double tdz = z_end - z_start;
    double odx = other.x_end - other.x_start;
    double ody = other.y_end - other.y_start;
    double odz = other.z_end - other.z_start;
    return Vector(x_start, y_start, z_start,
        tdy * odz - tdz * ody,
        tdz * odx - tdx * odz,
        tdx * ody - tdy * odx);
}

void Vector::operator *=(Vector& other) {
    Vector result = *this * other;
    x_end = result.x_end;
    y_end = result.y_end;
    z_end = result.z_end;
}

Vector Vector::operator*(double scalar) {
    return Vector(x_start, y_start, z_start, x_end * scalar, y_end * scalar, z_end * scalar);
}

void Vector::operator*=(double scalar) {
    x_end = x_start + scalar * (x_end - x_start);
    y_end = y_start + scalar * (y_end - y_start);
    z_end = z_start + scalar * (z_end - z_start);
}

Vector Vector::operator /(const Vector& other) {
    if (other.x_end - other.x_start == 0 || other.y_end - other.y_start == 0 || other.z_end - other.z_start == 0) {
        throw std::runtime_error("Division by zero error");
    }

    Vector other_reverse(other.x_start, other.y_start, other.z_start,
        other.x_start + 1.0 / (other.x_end - other.x_start),
        other.y_start + 1.0 / (other.y_end - other.y_start),
        other.z_start + 1.0 / (other.z_end - other.z_start));

    return *this * other_reverse;
}

void Vector::operator /=(Vector& other) {
    Vector result = *this / other;
    x_end = result.x_end;
    y_end = result.y_end;
    z_end = result.z_end;
}

double Vector::operator^(Vector& other) {
    double dot_product = (x_end - x_start) * (other.x_end - other.x_start) +
        (y_end - y_start) * (other.y_end - other.y_start) +
        (z_end - z_start) * (other.z_end - other.z_start);
    double length_product = length() * other.length();
    if (length_product == 0) {
        throw std::runtime_error("Division by zero error");
    }

    double cos_angle = dot_product / length_product;

    if (cos_angle > 1.0) {
        cos_angle = 1.0;
    }
    else if (cos_angle < -1.0) {
        cos_angle = -1.0;
    }

    return cos_angle;
}


void Vector::display() {
    std::cout << "(" << x_start << ", " << y_start << ", " << z_start << ") -> (" << x_end << ", " << y_end << ", " << z_end << ")" << std::endl;
}

void Vector::operator =(const Vector& other) {
    x_start = other.x_start;
    y_start = other.y_start;
    z_start = other.z_start;
    x_end = other.x_end;
    y_end = other.y_end;
    z_end = other.z_end;
}

bool Vector::operator ==(const Vector& other) {
    return x_start == other.x_start && y_start == other.y_start && z_start == other.z_start &&
        x_end == other.x_end && y_end == other.y_end && z_end == other.z_end;
}

bool Vector::operator !=(const Vector& other) {
    return !(*this == other);
}

bool Vector::operator >(const Vector& other) {
    return length() > other.length();
}

bool Vector::operator <(const Vector& other) {
    return length() < other.length();
}

bool Vector::operator >=(const Vector& other) {
    return length() >= other.length();
}

bool Vector::operator <=(const Vector& other) {
    return length() <= other.length();
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << "(" << v.x_start << ", " << v.y_start << ", " << v.z_start << ", " << v.x_end << ", " << v.y_end << ", " << v.z_end << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v) {
    in >> v.x_start >> v.y_start >> v.z_start >> v.x_end >> v.y_end >> v.z_end;
    return in;
}