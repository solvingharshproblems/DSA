#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
//Problem 1: Dijkstra's Algorithm for Shortest Path in Weighted Graph Using Priority Queue
//In Dijkstra's algorithm, we use a priority queue (min-heap) to efficiently fetch the next node with the smallest tentative distance.
//We also use a distance vector to keep track of the shortest distance from the source node to each node in the graph.
// This implementation finds the shortest path from a source node to all other nodes in a weighted graph with non-negative weights.
vector<int> dijkstra(int V,vector<vector<pair<int,int>>>& adj,int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    pq.push({0,source});
    dist[source]=0;
    while(!pq.empty()){
        int distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();  
        if(distance>dist[node]){
            continue;
        }
        for(auto neighbor:adj[node]){
            int edgeWeight=neighbor.second;
            int adjNode=neighbor.first;
            if(distance+edgeWeight<dist[adjNode]){
                dist[adjNode]=distance+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
} // TC=O(E log V) SC=O(V) 
int main(){
    int V=5;
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1,10});
    adj[0].push_back({2,3});
    adj[1].push_back({2,1});
    adj[1].push_back({3,2});    
    adj[2].push_back({1,4});
    adj[2].push_back({3,8});
    adj[2].push_back({4,2});
    adj[3].push_back({4,7});
    adj[4].push_back({3,9});
    int source=0;
    vector<int> distances=dijkstra(V,adj,source);
    for(int i=0;i<V;i++){
        cout<<"Distance from source "<<source<<" to node "<<i<<" is "<<distances[i]<<endl;
    }
    return 0;
}