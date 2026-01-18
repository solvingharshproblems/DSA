#include <iostream>
using namespace std;
//Problem 1: Shortest Path in Directed Acyclic Graph (DAG) using Topological Sort
//Given a weighted DAG and a source vertex, find the shortest path from the source to all other vertices.
//For Optimal Approach, we will use Topological Sort followed by relaxation of edges.
void topoSort(int node,vector<vector<pair<int,int>>>& adj,vector<bool>& visited,stack<int>& st){
    visited[node]=true;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor.first]){
            topoSort(neighbor.first,adj,visited,st);
        }
    }
    st.push(node);
}
vector<int> shortestPathDAG(int V,int source,vector<vector<pair<int,int>>>& adj){
    stack<int> st;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topoSort(i,adj,visited,st);
        }
    }
    vector<int> distance(V,INT_MAX);
    distance[source]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(distance[node]!=INT_MAX){
            for(auto neighbor:adj[node]){
                if(distance[node]+neighbor.second<distance[neighbor.first]){
                    distance[neighbor.first]=distance[node]+neighbor.second;    
                }
            }
        }
    }
    return distance;
} // TC=O(V+E) SC=O(V) for visited + O(V) for stack + O(V) for distance + O(E) for adjacency list
int main(){
    int V=6;
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1,2});
    adj[0].push_back({4,1});
    adj[1].push_back({2,3});
    adj[2].push_back({3,6});
    adj[4].push_back({2,2});
    adj[4].push_back({5,4});
    adj[5].push_back({3,1});
    int source=0;
    vector<int> distances=shortestPathDAG(V,source,adj);
    cout<<"Shortest distances from source vertex "<<source<<":"<<endl;
    for(int i=0;i<V;i++){
        if(distances[i]==INT_MAX){
            cout<<"Vertex "<<i<<": "<<"Infinity"<<endl;
        }else{
            cout<<"Vertex "<<i<<": "<<distances[i]<<endl;
        }
    }
    return 0;
}