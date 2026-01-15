#include <iostream>
using namespace std;
//Problem 1: Topological Sort in Directed Acyclic Graph (Using DFS)
//Any linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
//For Optimal Approach, we will use DFS traversal to perform topological sort in a directed acyclic graph.
bool DFS(int node,int V,vector<vector<int>>& adj,vector<int>& visited,vector<int>& topoSort,int& index){
    visited[node]=1;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            if(!DFS(neighbor,V,adj,visited,topoSort,index)){
                return false;
            }
        }
        else if(topoSort[neighbor]==-1){
            return false;
        }
    }
    topoSort[index]=node;
    index--;
    return true;
}
void TopologicalSort(int V,vector<vector<int>>& adj){
    vector<int> visited(V,0);
    vector<int> topoSort(V,0);
    int index=V-1;
    for(int start=0;start<V;start++){
        if(!visited[start]){
            if(!DFS(start,V,adj,visited,topoSort,index)){
                cout<<"Graph is not a DAG, topological sort not possible."<<endl;
                return;
            }
        }
        else{
            continue;
        }
    }
    cout<<"Topological Sort Order: ";
    for(int i=0;i<V;i++){
        cout<<topoSort[i]<<" ";
    }
    cout<<endl;
} // TC=O(V+E) SC=O(V) for visited + O(V) for topoSort + O(V) for recursion stack
int main(){
    int V=6;
    vector<vector<int>> adj(V);;
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);    
    adj[2].push_back(3);
    adj[3].push_back(1);
    TopologicalSort(V,adj);
    return 0;
}