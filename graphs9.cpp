#include <iostream>
using namespace std;
//Problem 1: Detect Cycle in Directed Graph (Using DFS)
//For Optimal Approach, we will use DFS traversal to detect a cycle in a directed graph.
bool DFS(int node,int V,vector<vector<int>>& adj,vector<int>& visited,vector<int>& recStack){
    visited[node]=1;
    recStack[node]=1;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            if(DFS(neighbor,V,adj,visited,recStack)){
                return true;
            }
        }
        else if(recStack[neighbor]){
            return true;
        }
    }
    recStack[node]=0;
    return false;
}
bool isCyclicDirectedDFS(int V,vector<vector<int>>& adj){
    vector<int> visited(V,0);
    vector<int> recStack(V,0);
    for(int start=0;start<V;start++){
        if(!visited[start]){
            if(DFS(start,V,adj,visited,recStack)){
                return true;
            }
        }
        else{
            continue;
        }
    }
    return false;
} // TC=O(V+E) SC=O(V) for visited + O(V) for recStack + O(V) for recursion stack
//Problem 2: Find Eventual Safe States (Using DFS)
//Eventual Safe States are those nodes from which we cannot reach any cycle.
//For Optimal Approach, we will use DFS traversal to find all eventual safe states in a directed graph.
bool DFSHelper(int node,int V,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVisited,vector<int>& safe){
    visited[node]=1;
    pathVisited[node]=1;
    safe[node]=0;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            if(!DFSHelper(neighbor,V,adj,visited,pathVisited,safe)){
                return false;
            }
        }
        else if(pathVisited[neighbor]){
            return false;
        }
    }
    pathVisited[node]=0;
    safe[node]=1;
    return true;
}
void findSafeStatesDFS(int V,vector<vector<int>>& adj){
    vector<int> visited(V,0);
    vector<int> safe(V,0);
    vector<int> pathVisited(V,0);
    for(int start=0;start<V;start++){
        if(!visited[start]){
            DFSHelper(start,V,adj,visited,pathVisited,safe);
        }
    }
    for(int i=0;i<V;i++){
        if(safe[i]){
            cout<<i<<" ";
        }
    }
} // TC=O(V+E) SC=O(V) for visited + O(V) for safe + O(V) for recursion stack
int main(){
    int V=4;
    vector<vector<int>> adj(V);;
    adj[0]={1};
    adj[1]={2};
    adj[2]={0};
    adj[3]={};
    if(isCyclicDirectedDFS(V,adj)){
        cout<<"Graph contains cycle"<<endl;
    }
    else{
        cout<<"Graph doesn't contain cycle"<<endl;
    }
    cout<<"Eventual Safe States are: ";
    findSafeStatesDFS(V,adj);
    cout<<endl;
    return 0;
}