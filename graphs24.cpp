#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
//Problem 1: Finding Strongly Connected Components (SCC) in a Directed Graph using Kosaraju's Algorithm
//A strongly connected component is a maximal set of vertices such that each vertex is reachable from every other vertex in the set.
//In Kosaraju's Algorithm, firstly we sort all the edges according to their finishing times in decreasing order using DFS and store them in a stack.
//Then we reverse the graph and perform DFS according to the finishing times to get all strongly connected components.
//Then we can count the number of strongly connected components and also find the largest strongly connected component.
void DFS(int node,vector<bool>& visited,stack<int>& st,vector<vector<int>>& adj){
    visited[node]=true;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            DFS(neighbor,visited,st,adj);
        }
    }
    st.push(node);
}
void DFSTranspose(int node,vector<bool>& visited,vector<vector<int>>& transposedAdj){
    visited[node]=true;
    for(auto neighbor:transposedAdj[node]){
        if(!visited[neighbor]){
            DFSTranspose(neighbor,visited,transposedAdj);
        }
    }
}
int KosarajuSCC(int V,vector<vector<int>>& edges){
    vector<vector<int>> adj(V);
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
    }
    stack<int> st;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i,visited,st,adj);
        }
    }
    vector<vector<int>> transposedAdj(V);
    for(int i=0;i<V;i++){
        for(auto neighbor:adj[i]){
            transposedAdj[neighbor].push_back(i);
        }
    }
    fill(visited.begin(),visited.end(),false);
    int sccCount=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            sccCount++;
            stack<int> tempSt;
            DFSTranspose(node,visited,transposedAdj); 
        }
    }
    return sccCount;
} // TC=O(V+E) SC=O(V+E) where V is the number of vertices and E is the number of edges.
int main(){
    int V=5;
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{1,3},{3,4}};
    cout<<"Number of Strongly Connected Components: "<<KosarajuSCC(V,edges)<<endl;  
    return 0;
}