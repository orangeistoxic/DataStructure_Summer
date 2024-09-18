#include <iostream>
#include <string.h>

using namespace std;

int main(){

    string ipt;

    while(cin>>ipt){
        if(ipt=="0"){
            break;
        }
    int tot=0;
    for(int i=0;i<ipt.length();i++){
        if(i%2==0){
            tot+=int(ipt[i])-48;
            
        }
        else{
            tot-=int(ipt[i])-48;
            
        }
        
    }
    
    if(tot%11==0){
        cout<<ipt<<" is a multiple of 11."<<endl;
    }
    else{
        cout<<ipt<<" is not a multiple of 11."<<endl;
    }
    }
}