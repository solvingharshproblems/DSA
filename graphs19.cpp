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
//Problem 2: Find the City with the Smallest Number of Neighbors at a Threshold Distance
//You are given an integer n representing the number of cities and a 2D array edges where edges[i] = [u, v, weight] indicates that there is a bidirectional road between cities u and v with a distance equal to weight.
//You are also given an integer distanceThreshold. The task is to find the city with the smallest number of neighbors at a distance less than or equal to distanceThreshold. If there are multiple such cities, return the city with the greatest number.
//For Optimal Approach, we will use Floyd Warshall Algorithm to find all pairs shortest paths and then count the number of reachable cities for each city.
int findTheCity(int n,vector<vector<int>>& edges,int distanceThreshold){
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    for(auto edge:edges){
        dist[edge[0]][edge[1]]=edge[2];
        dist[edge[1]][edge[0]]=edge[2]; 
    }
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){   
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }   
        }
    }
    int minCount=n;
    int resultCity=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                count++;
            }
        }
        if(count<=minCount){
            minCount=count; 
            resultCity=i;
        }
    }
    return resultCity;
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
    vector<vector<int>> edges={
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int distanceThreshold=4;
    int city=findTheCity(n,edges,distanceThreshold);
    cout<<"City with the smallest number of neighbors at distance threshold "<<distanceThreshold<<": "<<city<<endl;
    return 0;
}