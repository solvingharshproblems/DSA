#include <iostream>
using namespace std;
//Problem 1: Prim's Algorithm for Minimum Spanning Tree
//You are given a connected, undirected graph represented as an adjacency matrix. The task is to find the Minimum Spanning Tree (MST) of the graph using Prim's Algorithm.
//Prim's Algorithm is a greedy algorithm that builds the MST by starting from an arbitrary vertex and repeatedly adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.
//For the implementation, we will use a priority queue to efficiently get the minimum weight edge at each step and a boolean array to keep track of vertices included in the MST.
int primMST(vector<vector<int>>& graph){
    int n=graph.size();
    vector<bool> inMST(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0}); // {weight, vertex}
    int totalWeight=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(inMST[it.second]) continue;
        inMST[it.second]=true;
        totalWeight+=it.first;
        for(int v=0;v<n;v++){
            if(graph[it.second][v]!=-1 && !inMST[v]){
                pq.push({graph[it.second][v],v});
            }
        }
    }
    return totalWeight;
} // TC=O(E log V) SC=O(V)
int main(){
    int n=5;
    vector<vector<int>> graph={
        {0,2,-1,6,-1},
        {2,0,3,8,5},
        {-1,3,0,-1,7},
        {6,8,-1,0,9},
        {-1,5,7,9,0}
    };  
    cout<<"Total weight of MST is: "<<primMST(graph)<<endl;
    return 0;
}