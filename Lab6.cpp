#include<iostream>

using namespace std;

int main(){
    int N,M;
    while(cin>>N>>M){
        if(N==0 && M==0){
            cout<<"0 0"<<endl;
            break;
        }

        int *arr1 = new int[N];
        int *arr2 = new int[N];
        for(int i=0; i<N; i++){
            cin>>arr1[i];
            arr2[i]=arr1[i]%M;
        }
        bool isSorted=true;
        while(isSorted){
            isSorted = false;
            for(int i=0; i<N-1;i++){
                if(arr2[i]>arr2[i+1]){
                    swap(arr2[i],arr2[i+1]);
                    swap(arr1[i],arr1[i+1]);
                    isSorted=true;
                }
                else if(arr2[i]==arr2[i+1]){
                    int moda = arr1[i]%2;
                    int modb = arr1[i+1]%2;
                    if(moda==0 && modb!=0){
                        swap(arr2[i],arr2[i+1]);
                        swap(arr1[i],arr1[i+1]);
                        isSorted = true;
                    }
                    else if(moda==0 && modb==0){
                        if(arr1[i]>arr1[i+1]){
                            swap(arr2[i],arr2[i+1]);
                            swap(arr1[i],arr1[i+1]);
                            isSorted = true;
                        }
                    }
                    else if(moda!=0 && modb!=0){
                        if(arr1[i]<arr1[i+1]){
                            swap(arr2[i],arr2[i+1]);
                            swap(arr1[i],arr1[i+1]);
                            isSorted = true;
                        }
                    }
                }
            }
        }
        
        cout<<N<<" "<<M<<endl;
        for(int i=0; i<N; i++){
            cout<<arr1[i]<<endl;
        }
    }



    return 0;
}