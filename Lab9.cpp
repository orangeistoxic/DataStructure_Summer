#include<iostream>
#include<string.h>

using namespace std;

int main(){
    long long int N;

    while(cin>>N){
        if(N==0){
            break;
        }
        else if(N<10){
            cout<<N<<endl;
        }
        else{
            while(N>9){
                long long int sum=0;
                while(N>0){
                    sum+=N%10;
                    N/=10;
                }
                N=sum;
            }
            cout<<N<<endl;
        }
    }
    return 0;
}