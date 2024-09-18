#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string ipt1,ipt2;

    while(cin>>ipt1>>ipt2){
        if(ipt1 == "0" && ipt2 == "0"){
            break;
        }

        bool isLastCarry = false;
        int countCarry=0;
        int i=ipt1.length()-1;
        int j=ipt2.length()-1;
        while(i>=0 && j>=0){
            if(int(ipt1[i])-48 + int(ipt2[j])-48 > 9){
                isLastCarry = true;
                countCarry++;
            }
            else if (int(ipt1[i]) - 48 + int(ipt2[j]) - 48 == 9 && isLastCarry)
            {
                isLastCarry = true;
                countCarry++;
            }
            else{
                isLastCarry = false;
            }
            i--;
            j--;
        }
        if(i<0){
            while(j>=0 && isLastCarry){
                if(int(ipt2[j])-48 == 9){
                    isLastCarry = true;
                    countCarry++;
                }
                else{
                    isLastCarry = false;
                }
                j--;
            }
        }
        else if(j<0){
            while(i>=0 && isLastCarry){
                if(int(ipt1[i])-48 == 9){
                    isLastCarry = true;
                    countCarry++;
                }
                else{
                    isLastCarry = false;
                }
                i--;
            }
        }
        

        if(countCarry == 0){
            cout<<"No carry operation."<<endl;
        }
        else if(countCarry == 1){
            cout<<countCarry<<" carry operation."<<endl;
        }
        else{
            cout<<countCarry<<" carry operations."<<endl;
        }
    }

    return 0;
}