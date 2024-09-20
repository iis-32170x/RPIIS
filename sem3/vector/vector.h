#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector
{
private:
    double x_start;
    double y_start;
    double z_start;
    double x_end;
    double y_end;
    double z_end;

public:
    Vector();
    Vector(double x_start, double y_start, double z_start, double x_end, double y_end, double z_end);

    double length() const;
    Vector operator +(const Vector& other);
    void operator +=(Vector& other);
    Vector operator -(const Vector& other);
    void operator -=(Vector& other);
    Vector operator *(const Vector& other);
    void operator *=(Vector& other);
    Vector operator*(double scalar);
    void operator*=(double scalar);
    Vector operator /(const Vector& other);
    void operator /=(Vector& other);
    double operator^(Vector& other);
    void display();
    void operator =(const Vector& other);
    bool operator ==(const Vector& other);
    bool operator !=(const Vector& other);
    bool operator >(const Vector& other);
    bool operator <(const Vector& other);
    bool operator >=(const Vector& other);
    bool operator <=(const Vector& other);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);
};

#endif // VECTOR_H
