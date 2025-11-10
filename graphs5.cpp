#include <iostream>
using namespace std;
//Problem 1: Detect a cycle in an Undirected Graph (using BFS)
//For Optimal Approach, we will declare a queue of pairs to store the node and its parent while traversing the graph using BFS 
//and a visited array to keep track of visited nodes.
//If we encounter a visited node that is not the parent of the current node, then we have found a cycle in the graph.
bool detectUniCycleBFS(int src,vector<int> adj[],vector<bool> &visited){
    queue<pair<int,int>> q;
    visited[src]=true;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it]=true;
                q.push({it,node});
            }
            else if(parent!=it){
                return true; 
            }
        }
    }
    return false; 
} 
//what if the graph is disconnected? Then we need to call the BFS function for all unvisited nodes.
bool isCycleUniBFS(int n,vector<int> adj[]){
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(detectUniCycleBFS(i,adj,visited)){
                return true;
            }
        }
    }
    return false;
} // TC=O(n+2e), SC=O(2n)
//Problem 2: Detect a cycle in a UnDirected Graph (using DFS)
//For Optimal Approach, we will use a recursive DFS function to traverse the graph and keep track of the nodes in the current recursion stack using a separate array.
//If we encounter a node that is already in the recursion stack, then we have found a cycle in the graph.
bool detectUniCycleDFS(int node,int parent,vector<int> adj[],vector<bool> &visited){
    visited[node]=true;
    for(auto it: adj[node]){
        if(!visited[it]){
            if(detectUniCycleDFS(it,node,adj,visited)){
                return true;
            }
        }
        else if(it!=parent){
            return true; 
        }
    }
    return false; 
}
//what if the graph is disconnected? Then we need to call the DFS function for all unvisited nodes.
bool isCycleUniDFS(int n,vector<int> adj[]){
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(detectUniCycleDFS(i,-1,adj,visited)){
                return true;
            }
        }
    }
    return false;
} // TC=O(n+2e), SC=O(2n)
int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int m;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<int> adj[n];
    cout<<"Enter edges (u v) format:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycleFound=isCycleUniBFS(n,adj);
    if(cycleFound){
        cout<<"Theres a cycle."<<endl;
    }
    else{
        cout<<"There is no cycle."<<endl;
    }
    bool cycleFoundDFS=isCycleUniDFS(n,adj);
    if(cycleFoundDFS){
        cout<<"Theres a cycle."<<endl;
    }
    else{
        cout<<"There is no cycle."<<endl;
    }
    return 0;
}