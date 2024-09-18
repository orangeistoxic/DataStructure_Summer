#include <iostream>

using namespace std;

int main(){
    int n,count=1;
    

    while(cin>>n){
        bool isB2 = true;
        int *ptr=new int[n];
        int *diff= new int[n-1];
        for(int i=0; i<n; i++){
            cin>>ptr[i];
            if(ptr[i]<1){
                isB2=false;
            }
            if(i>=1){
                diff[i-1]=ptr[i]-ptr[i-1];
                if(diff[i-1]<=0){
                    isB2=false;
                }
            }
        }
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1;j++){
                if(diff[i]==diff[j]){
                    isB2=false;
                    break;
                }
            }
        }

        if(isB2){
            cout << "Case #" << count << ": It is a B2-Sequence.\n\n";
            count++;
        }
        else{
            cout << "Case #" << count << ": It is not a B2-Sequence.\n\n";
            count++;
        }
        

        
    }
}