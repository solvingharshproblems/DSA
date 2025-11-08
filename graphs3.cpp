#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Number of Provinces
//Given an adjacency matrix representing connections between cities, find the number of provinces (connected components) in the graph.
//For Optimal Approach, we can use either BFS or DFS to traverse the graph and count the number of connected components.
void DFS(int v,vector<int> graph[],vector<int> visited){
    visited[v]=1;
    for(auto it:graph[v]){
        if(!visited[it]){
            DFS(it,graph,visited);
        }
    }
}
int Provinces(int v,vector<vector<int>>& isConnected){
    vector<int> adj[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> visited(v,0);
    int count=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            count++;
            DFS(i,adj,visited);
        }
    }
    return count;
} // TC=O(v+2e) SC=O(v+2e)+O(v)
int main(){
    int v=3;
    vector<vector<int>> isConnected={{1,1,0},{1,1,0},{0,0,1}};
    int result=Provinces(v,isConnected);
    cout<<"Number of Provinces: "<<result<<endl;
    return 0;
}