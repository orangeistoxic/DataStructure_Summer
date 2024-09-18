#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>


using namespace std;

class vector3
{
    public:
    friend class matrix33;
    vector3(float=1, float=1, float=3);
    vector3(const vector3 &);
    ~vector3();

    vector3 operator+(const vector3 &);
    vector3 operator-(const vector3 &);
    vector3 operator*(float scalar);
    float   operator*(const vector3 &);
    friend vector3 operator*(float scalar, const vector3 &);
    vector3 operator/(float scalar);
    vector3& operator=(const vector3 &);
    vector3& operator+=(const vector3 &);
    vector3& operator-=(const vector3 &);
    vector3& operator*=(float scalar);
    vector3& operator/=(float scalar);
    float& operator[](float i);
    bool operator==(const vector3 &) const;
    bool operator!=(const vector3 &) const;
    
     
    double length();
    void printVector3();


    private:
    float x;
    float y;
    float z;
};
#endif

