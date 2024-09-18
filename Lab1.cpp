#include <iostream>
#include <string.h>

using namespace std;

template <class T>

void Bubble_Sort(T ary){
    bool isSorted = true;
    while(isSorted){
        isSorted = false;
        for (int i = 0; i < 15; i++)
        {
            if(ary[i] > ary[i+1]){
                swap(ary[i], ary[i+1]);
                isSorted = true;
            }
        }
    }

    for (int i = 0; i <= 15; i++)
    {
        cout << ary[i] <<endl;
    }

    cout << endl;
    
    
}

int main(){

    int arr_i[] = {51, 28, 100, 85, 12, 87, 71, 62, 44, 12, 57, 49, 59, 99, 29, 51};
    float arr_f[] = {17.76, 17.05, 17.13, 12.59, 16.64, 12.38, 15.88, 16.20, 16.95, 16.73, 16.83, 11.57, 15.76, 13.49, 15.88, 17.92};
    string arr_s[] = {
        "TXWBxfYRsy",
        "xZ0yADSfPz",
        "hgbsTNklpb",
        "koItyjTgbp",
        "YUvSXobjC5",
        "1mx6Cp8Jmm",
        "yYzQ4r9Ufi",
        "69zBs6h4cL",
        "2HrG7jSl5Y",
        "6CouycGPxJ",
        "2AFZUzkd58",
        "TJOYEOvNqL",
        "4Q8RpSJtXG",
        "XaVxGXytDW",
        "atjHwsTyUC",
        "SiXVWYqKaT",
    };

    Bubble_Sort(arr_i);
    Bubble_Sort(arr_f);
    Bubble_Sort(arr_s);

}