#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int line;
    cin >> line;

    int letter[26];

    for(int i=0;i<26;i++){
        letter[i] = 0;
    }   
    getchar();

    int max = 0;

    while(line--){
        string str;
        getline(cin, str);

        for(int i=0;i<str.length();i++){
            if(str[i]>='a' && str[i]<='z'){
                letter[str[i]-'a']++;
                if(letter[str[i]-'a']>max){
                    max = letter[str[i]-'a'];
                }

            }
            if(str[i]>='A' && str[i]<='Z'){
                letter[str[i]-'A']++;
                if(letter[str[i]-'A']>max){
                    max = letter[str[i]-'A'];
                }
            }
        }
    }

    while(max--){
        for(int i=0;i<26;i++){
            if(letter[i]==max+1){
                cout << (char)(i+'A') << " " << letter[i] << endl;
            }
        }
    }



    
}