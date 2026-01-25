#include <iostream>
using namespace std;
//Problem 1: Floyd Warshall Algorithm for All Pairs Shortest Path
//You are given a weighted directed graph represented as an adjacency matrix. The task is to find the shortest paths between every pair of vertices in the graph.
//Floyd Warshall Algorithm is a dynamic programming algorithm used to find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).
//In this algorithm, we iteratively update the distance matrix by considering each vertex as an intermediate point.
void floydWarshall(vector<vector<int>>& graph){
    int n=graph.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==-1){
                graph[i][j]=1e9; // Use a large value to represent infinity
            }
            if(i==j){
                graph[i][j]=0; // Distance to self is zero
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(graph[i][i]<0){
            cout<<"Negative weight cycle detected"<<endl;
            return;
        }
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1e9){
                graph[i][j]=-1; // Convert back to -1 for no path
            }
        }
    }
} // TC=O(N^3) SC=O(N^2)
int main(){
    int n=4;
    vector<vector<int>> graph={
        {0,3,-1,7},
        {-1,0,2,-1},
        {-1,-1,0,1},
        {-1,-1,-1,0}
    };
    floydWarshall(graph);
    cout<<"All Pairs Shortest Path Matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}