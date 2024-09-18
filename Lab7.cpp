#include <iostream>
#include <string.h>

using namespace std;    

int main(){
    int N;
    cin >> N;
    int count=1;
    while(count<=N){
        int size;
        char c;
        cin>>c>>c>>size;

        bool isSymmetric = true;
        long long int arr[size][size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cin>>arr[i][j];
                if(arr[i][j]<0){
                    isSymmetric = false;
                }
            }
        }
       
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(arr[i][j] != arr[size-1-i][size-1-j]){
                    isSymmetric = false;
                    break;
                }
            }
            
        }

        cout<< "Test #"<<count<<": "<<(isSymmetric ? "Symmetric." : "Non-symmetric.")<<endl;
        count++;
    }
}