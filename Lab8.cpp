#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string ipt;
    int N;
    cin>>N;
    getchar();
    string keyboardData=" `1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";

    while(N--){

        getline(cin,ipt);
        for(int i=0;i<ipt.length();i++){
            if(ipt[i]>='A' && ipt[i]<='Z'){
                ipt[i]=ipt[i]+32;
            }
            if(ipt[i]==' '){
                cout<<" ";
                continue;
            }
            for(int j=1;j<keyboardData.length();j++){
                if(ipt[i]==keyboardData[j]){
                    cout<<keyboardData[j-2];
                    break;
                }
            }
        }

        cout<<endl;
    }
    return 0;
}