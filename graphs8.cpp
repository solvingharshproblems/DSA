#include <iostream>
using namespace std;
//Problem 1: Bipartite Graph Check (Using BFS)
//Given an undirected graph, check if it is bipartite or not.
//A graph is bipartite if we can color its vertices using two colors such that no two adjacent vertices have the same color.
//Note: A linear graph is always bipartite.Also, any graph with even length cycle is bipartite.
//For Optimal Approach, we will start BFS from each uncolored node and try to color the graph using two colors.
bool isBipartiteBFS(int V,vector<vector<int>>& adj){
    vector<int> color(V,-1); 
    for(int start=0;start<V;start++){
        if(color[start]==-1){
            queue<int> q;
            q.push(start);
            color[start]=0; 
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto neighbor:adj[node]){
                    if(color[neighbor]==-1){
                        color[neighbor]=1-color[node];
                        q.push(neighbor);
                    }
                    else if(color[neighbor]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
} // TC=O(V+E) SC=O(V) for color array + O(V) for queue
int main(){
    int v=5;
    vector<vector<int>> adj(v);
    adj[0]={1,3};
    adj[1]={0,2};
    adj[2]={1,4};
    adj[3]={0,4};
    adj[4]={2,3};
    if(isBipartiteBFS(v,adj)){
        cout<<"The graph is Bipartite"<<endl;
    }
    else{
        cout<<"The graph is not Bipartite"<<endl;
    }
    return 0;
}