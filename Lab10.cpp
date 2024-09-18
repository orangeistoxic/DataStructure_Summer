#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int M , N, Q;
        cin>>M>>N>>Q;
        char arr[M][N];
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cin>>arr[i][j];
            }
        }
        int x, y;
        cout<<M<<" "<<N<<" "<<Q<<endl;
        while(Q--){
            cin>>x>>y;
            char alpha = arr[x][y];
            //cout<<"alpha: "<<alpha<<" | ";
            int count = 1;
            bool isMax = false;
            while(!isMax){
                int range = (count/2)+1;
                if(x+range>=M || y+range>=N || x-range<0 || y-range<0){
                    //cout<<"x: "<<x<<" y: "<<y<<" range: "<<range<<" | ";
                    isMax = true;
                    break;
                }
                for(int i=x-range; i<=x+range; i++){
                    for(int j=y-range; j<=y+range; j++){
                        if(arr[i][j]!=alpha){
                            //cout<<"i: "<<i<<" j: "<<j<<" arr[i][j]: "<<arr[i][j]<<" | ";
                            isMax = true;
                            break;
                        }
                    }
                    if(isMax){
                        break;
                    }
                }

                if(!isMax){
                    count+=2;
                }
            }

            cout<<count<<endl;

        }
    }
    return 0;
}