#include<iostream>
#include <cmath>
#include <iomanip>
#include "110611010_matrix33.h"

using namespace std;

matrix33::matrix33(vector3 vec1, vector3 vec2, vector3 vec3){
    this->vec1 = vec1;
    this->vec2 = vec2;
    this->vec3 = vec3;
}
matrix33::matrix33(const matrix33 &m){
    vec1 = m.vec1;
    vec2 = m.vec2;
    vec3 = m.vec3;
}
matrix33::~matrix33(){

}

matrix33 matrix33::operator+(const matrix33 &m){
    return matrix33(vec1 + m.vec1, vec2 + m.vec2, vec3 + m.vec3);
}
matrix33 matrix33::operator-(const matrix33 &m){
    return matrix33(vec1 - m.vec1, vec2 - m.vec2, vec3 - m.vec3);
}
matrix33 matrix33::operator*(float scalar){
    return matrix33(vec1 * scalar, vec2 * scalar, vec3 * scalar);
}
matrix33 matrix33::operator*(const matrix33 &m){
    matrix33 temp;
    temp.vec1 = vector3(vec1.x * m.vec1.x + vec2.x * m.vec1.y + vec3.x * m.vec1.z,
                        vec1.y * m.vec1.x + vec2.y * m.vec1.y + vec3.y * m.vec1.z,
                        vec1.z * m.vec1.x + vec2.z * m.vec1.y + vec3.z * m.vec1.z);
    temp.vec2 = vector3(vec1.x * m.vec2.x + vec2.x * m.vec2.y + vec3.x * m.vec2.z,
                        vec1.y * m.vec2.x + vec2.y * m.vec2.y + vec3.y * m.vec2.z,
                        vec1.z * m.vec2.x + vec2.z * m.vec2.y + vec3.z * m.vec2.z);
    temp.vec3 = vector3(vec1.x * m.vec3.x + vec2.x * m.vec3.y + vec3.x * m.vec3.z,
                        vec1.y * m.vec3.x + vec2.y * m.vec3.y + vec3.y * m.vec3.z,
                        vec1.z * m.vec3.x + vec2.z * m.vec3.y + vec3.z * m.vec3.z);

    return temp;
    
}
matrix33 operator*(float scalar, const matrix33 &m){
    return matrix33(scalar * m.vec1, scalar * m.vec2, scalar * m.vec3);
}
matrix33 matrix33::operator/(float scalar){
    return matrix33(vec1 / scalar, vec2 / scalar, vec3 / scalar);
}
matrix33& matrix33::operator=(const matrix33 &m){
    vec1 = m.vec1;
    vec2 = m.vec2;
    vec3 = m.vec3;
    return *this;
}
matrix33& matrix33::operator+=(const matrix33 &m){
    vec1 += m.vec1;
    vec2 += m.vec2;
    vec3 += m.vec3;
    return *this;
}
matrix33& matrix33::operator-=(const matrix33 &m){
    vec1 -= m.vec1;
    vec2 -= m.vec2;
    vec3 -= m.vec3;
    return *this;
}
matrix33& matrix33::operator*=(float scalar){
    vec1 *= scalar;
    vec2 *= scalar;
    vec3 *= scalar;
    return *this;
}
matrix33& matrix33::operator/=(float scalar){
    vec1 /= scalar;
    vec2 /= scalar;
    vec3 /= scalar;
    return *this;
}
vector3& matrix33::operator[](float i){
    if(i == 0){
        
        return vec1;
    }
    else if(i == 1){
        
        return vec2;
    }
    else if(i == 2){
       
        return vec3;
    }
    else{
        throw "Index out of bounds";
    }
}

bool matrix33::operator==(const matrix33 &m) const{
    return vec1 == m.vec1 && vec2 == m.vec2 && vec3 == m.vec3;
}
bool matrix33::operator!=(const matrix33 &m) const{
    return ! (*this==m);
}

void matrix33::printMatrix(){
    cout<<right;
    cout << setw(4) << vec1.x << setw(4) << vec2.x << setw(4) << vec3.x << endl;
    cout << setw(4) << vec1.y << setw(4) << vec2.y << setw(4) << vec3.y << endl;
    cout << setw(4) << vec1.z << setw(4) << vec2.z << setw(4) << vec3.z << endl;

}

int matrix33::determinant(){
    return vec1.x * (vec2.y * vec3.z - vec2.z * vec3.y) - vec1.y * (vec2.x * vec3.z - vec2.z * vec3.x) + vec1.z * (vec2.x * vec3.y - vec2.y * vec3.x);
}

matrix33 matrix33::invert(){
    int det = determinant();
    if(det == 0){
        cout << "Determinant is 0, matrix is not invertible" << endl;
        return *this;
    }
    matrix33 temp;
    temp[0][0] = (vec2.y * vec3.z - vec2.z * vec3.y) / det;
    temp[0][1] = (vec1.z * vec3.y - vec1.y * vec3.z) / det;
    temp[0][2] = (vec1.y * vec2.z - vec1.z * vec2.y) / det;
    temp[1][0] = (vec2.z * vec3.x - vec2.x * vec3.z) / det;
    temp[1][1] = (vec1.x * vec3.z - vec1.z * vec3.x) / det;
    temp[1][2] = (vec1.z * vec2.x - vec1.x * vec2.z) / det;
    temp[2][0] = (vec2.x * vec3.y - vec2.y * vec3.x) / det;
    temp[2][1] = (vec1.y * vec3.x - vec1.x * vec3.y) / det;
    temp[2][2] = (vec1.x * vec2.y - vec1.y * vec2.x) / det;
    return temp;
}

void matrix33::identity(){
    vec1 = vector3(1, 0, 0);
    vec2 = vector3(0, 1, 0);
    vec3 = vector3(0, 0, 1);
}