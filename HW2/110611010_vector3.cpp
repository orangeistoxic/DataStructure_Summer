#include<iostream>
#include <cmath>
#include "110611010_vector3.h"

using namespace std;

vector3::vector3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}
vector3::vector3(const vector3 &v){
    x = v.x;
    y = v.y;
    z = v.z;
}
vector3::~vector3(){

}

vector3 vector3::operator+(const vector3 &v){
    return vector3(x + v.x, y + v.y, z + v.z);
}
vector3 vector3::operator-(const vector3 &v){
    return vector3(x - v.x, y - v.y, z - v.z);
}
vector3 vector3::operator*(float scalar){
    return vector3(x * scalar, y * scalar, z * scalar);
}
float vector3::operator*(const vector3 &v){
    return x * v.x + y * v.y + z * v.z;
}
vector3 operator*(float scalar, const vector3 &v){
    return vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}
vector3 vector3::operator/(float scalar){
    return vector3(x / scalar, y / scalar, z / scalar);
}
vector3& vector3::operator=(const vector3 &v){
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
vector3& vector3::operator+=(const vector3 &v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}
vector3& vector3::operator-=(const vector3 &v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}
vector3& vector3::operator*=(float scalar){
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}
vector3& vector3::operator/=(float scalar){
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}
float& vector3::operator[](float j){
    if(j == 0){
        
        return x;
    }
    else if(j == 1){
        
        return y;
    }
    else if(j == 2){
        
        return z;
    }
    else{
        throw "Invalid index";
    }
}
bool vector3::operator==(const vector3 &v) const{
    return x == v.x && y == v.y && z == v.z;

}
bool vector3::operator!=(const vector3 &v) const{
    return ! (*this == v);
}

double vector3::length(){
    return sqrt(x*x + y*y + z*z);
}

void vector3::printVector3(){
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}