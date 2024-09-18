#include <iostream>
#include "110611010_matrix33.h"

using namespace std;

int main(){
    matrix33 m1;
    m1.printMatrix();
    m1[0][1] = 100;
    m1[2][2] = 200;
    cout<<endl;
    m1.printMatrix();
    return 0;
}
