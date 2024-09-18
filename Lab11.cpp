#include<iostream>
#include<string.h>

using namespace std;

int main(){
    bool isChange[4]={false, false, false, false};
    bool isNoodle = false;
    bool isLegal = true;
    string howMuch[4] = {"mashimashi", "mashi", "sukuname", "nuki"};
    string type[4]= {"yasai", "ninniku", "abura", "karame"};
    string order[5]={"koramen","0","0","0","0"};

    string ipt,much;
    while(cin>>ipt && isLegal){
        if(ipt == "dairamen" || ipt == "koramen"){
            if(isNoodle){
                isLegal = false;
                break;
            }
            isNoodle = true;
            order[0] = ipt;
        }
        else if(ipt == "sonomama"){
            if(isChange[0] || isChange[1] || isChange[2] || isChange[3]){
                isLegal = false;
                break;
            }
            for(int i=0; i<4; i++){
                isChange[i] = true;
            }
        }
        else if(ipt == "zen"){
            if(isChange[0] || isChange[1] || isChange[2] || isChange[3]){
                isLegal = false;
                break;
            }
            for(int i=0; i<4; i++){
                isChange[i] = true;
            }
            cin>>much;
            isLegal = false;
            for (int i = 0; i < 4; i++)
            {
                if (much == howMuch[i])
                {
                    isLegal = true;
                    break;
                }
            }
            for(int i=0; i<4; i++){
                order[i+1] = much;
            }

        }
        else {
            isLegal = false;
            for(int i=0; i<4; i++){
                if(ipt == type[i]){
                    isLegal = true;
                    if(isChange[i]){
                        isLegal = false;
                        break;
                    }
                    isChange[i] = true;
                    cin>>much;
                    isLegal = false;
                    for (int i = 0; i < 4; i++)
                    {
                        if (much == howMuch[i])
                        {
                            isLegal = true;
                            break;
                        }
                    }
                    order[i+1] = much;
                    break;
                }
            }
        }
        
    }
    if(isLegal ){
        cout<<order[0]<<endl;
        for(int i=1; i<5; i++){
            if(order[i] != "0"){
                cout<<type[i-1]<<" "<<order[i]<<endl;
            }
        }
    }
    else{
        cout << "imi wakannai"<<endl;
    }
    return 0;
}