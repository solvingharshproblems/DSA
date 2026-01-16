#include <iostream>
using namespace std;
//Problem 1: Detect Cycle in Directed Graph (Using BFS - Kahn's Algorithm)
//A cycle exists in a directed graph if we cannot include all vertices in the topological sort
bool DetectCycleDAG(int V,vector<vector<int>>& adj){
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
    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(count==V){
        return false; // No cycle
    }
    else{
        return true; // Cycle exists
    }
} // TC=O(V+E) SC=O(V) for indegree + O(V) for queue
int main(){
    int V=4;
    vector<vector<int>> adj(V);;
    adj[0]={1};
    adj[1]={2};
    adj[2]={0};
    adj[3]={2};
    if(DetectCycleDAG(V,adj)){
        cout<<"Graph contains a cycle."<<endl;
    }
    else{
        cout<<"Graph does not contain a cycle."<<endl;
    }
    return 0;
}