#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Topological Sort in Directed Acyclic Graph (Using DFS)
//Any linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
bool DFS(int node,int V,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVisited,vector<int>& topoSort,int& index){
    visited[node]=1;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            if(!DFS(neighbor,V,adj,visited,pathVisited,topoSort,index)){
                return false;
            }
        }
        else if(pathVisited[neighbor]){
            return false;
        }
    }
    pathVisited[node]=0;
    topoSort[index]=node;
    index--;
    return true;
}
void TopologicalSort(int V,vector<vector<int>>& adj){
    vector<int> visited(V,0);
    vector<int> topoSort(V,0);
    vector<int> pathVisited(V,0);
    int index=V-1;
    for(int start=0;start<V;start++){
        if(!visited[start]){
            if(!DFS(start,V,adj,visited,pathVisited,topoSort,index)){
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
} // TC=O(V+E) SC=O(V) for visited + O(V) for topoSort + O(V) for recursion stack + O(V) for pathVisited
//Problem 2: Kahn's Algorithm for Topological Sort (Using BFS)
//This is another approach to perform topological sort in a directed acyclic graph but using BFS traversal.
void KahnsTopologicalSort(int V,vector<vector<int>>& adj){
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto neighbor:adj[i]){
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topoSort;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(topoSort.size()!=V){
        cout<<"Graph is not a DAG, topological sort not possible."<<endl;
        return;
    }
    cout<<"Topological Sort Order: ";
    for(auto node:topoSort){
        cout<<node<<" ";
    }
    cout<<endl;
} // TC=O(V+E) SC=O(V) for indegree + O(V) for queue + O(V) for topoSort
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
    KahnsTopologicalSort(V,adj);
    return 0;
}