#ifndef MATRIX33_H
#define MATRIX33_H

#include"iostream"
#include"110611010_vector3.h"

using namespace std;


class matrix33 :public vector3
{
    public:
    
    matrix33(vector3 vec1 = vector3(), vector3 vec2 = vector3(), vector3 vec3 = vector3());
    matrix33(const matrix33 &);
    ~matrix33();

    matrix33 operator+(const matrix33 &);
    matrix33 operator-(const matrix33 &);
    matrix33 operator*(float scalar);
    matrix33 operator*(const matrix33 &);
    friend matrix33 operator*(float scalar, const matrix33 &);
    matrix33 operator/(float scalar);
    matrix33& operator=(const matrix33 &);
    matrix33& operator+=(const matrix33 &);
    matrix33& operator-=(const matrix33 &);
    matrix33& operator*=(float scalar);
    matrix33& operator/=(float scalar);
    vector3& operator[](float i);
    bool operator==(const matrix33 &) const;
    bool operator!=(const matrix33 &) const;

    void printMatrix();

    matrix33 invert();
    void identity();
    int determinant();

    private:
    vector3 vec1;
    vector3 vec2;
    vector3 vec3;

};

#endif