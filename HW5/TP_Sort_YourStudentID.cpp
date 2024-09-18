#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>

using namespace std;

void DFS(unordered_map<int, list<int>> &graph, int start, unordered_map<int, bool> &visited, stack<int> &s){
    visited[start] = true;
    for(auto it=graph[start].begin();it!=graph[start].end();it++){
        if(!visited[*it]){
            DFS(graph, *it, visited, s);
        }
    }
    s.push(start);
}

list<int> topologicalSort(unordered_map<int, list<int>> graph){
    list<int> result;
    unordered_map<int, bool> visited;
    stack<int> s;

    for(auto it=graph.begin();it!=graph.end();it++){
        visited.insert({it->first, false});
    } //set all visited to false

    for(auto it=graph.begin();it!=graph.end();it++){
        if(!visited[it->first]){
            DFS(graph, it->first, visited, s);
        }
    }

    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main(){
    int dataSize = 0;

    ofstream location_out;
    location_out.open("TP_Sort_YourStudentID.txt", ios::out | ios::app);

    ifstream fin("sample data.txt");
    while(fin>>dataSize){
        cout<<dataSize<<endl;

        unordered_map<int, list<int>> graph;

        for(int i=0;i<dataSize;i++){
            int data;
            fin>>data;
            cout<<data<<" ";
            graph.insert({data, list<int>()});
        }
        cout<<endl;
        int edgeSize;
        fin>>edgeSize;
        cout<<edgeSize<<endl;
        for(int i=0;i<edgeSize;i++){
            int from, to;
            char C;
            fin>>to>>C>>from;
            cout<<from<<" "<<to<<endl;
            graph[from].push_back(to);
        }

       list<int> result = topologicalSort(graph);

         for(auto it=result.begin();it!=result.end();it++){
              location_out<<*it<<" ";
         }
         location_out<<"\n\n";
    }
}