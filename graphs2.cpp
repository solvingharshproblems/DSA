#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//BFS in Graphs
//Here we traverse the graph level by level starting from a given source vertex.
//We use a queue data structure instead of a vector in adjacency list to keep track of vertices to be explored next.
//We also maintain a visited array to keep track of visited vertices to avoid processing a vertex more than once.
vector<int> BFS(int v,vector<int> graph[],int n){
    vector<int> visited(n,0);
    visited[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:graph[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
} // TC=O(v+2e) SC=O(3v)
//DFS in Graphs
//Here we traverse the graph depth-wise starting from a given source vertex.
//We use recursion to explore as far as possible along each branch before backtracking.
void DFSHelper(int node,vector<int> graph[],vector<int> &visited,vector<int> &dfs){
    visited[node]=1;
    dfs.push_back(node);
    for(auto it:graph[node]){
        if(!visited[it]){
            DFSHelper(it,graph,visited,dfs);
        }
    }
}
vector<int> DFS(int v,vector<int> graph[],int n){
    vector<int> visited(n,0);
    vector<int> dfs;
    DFSHelper(v,graph,visited,dfs);
    return dfs;
} // TC=O(v+2e) SC=O(3v)
int main(){
    int n=5;
    vector<int> graph[n];
    graph[0]={1,2};
    graph[1]={0,3,4};
    graph[2]={0};
    graph[3]={1};
    graph[4]={1};
    vector<int> bfs=BFS(0,graph,n);
    for(auto it:bfs){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> dfs=DFS(0,graph,n);
    for(auto it:dfs){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}