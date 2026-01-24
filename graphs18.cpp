#include <iostream>
using namespace std;
//Problem 1: Number of Ways to Arrive at Destination
//You are given an integer n representing the number of nodes in a weighted undirected graph, and a 2D array roads where roads[i] = [u, v, time] indicates that there is a bidirectional road between nodes u and v that takes time to travel.
//You need to find the number of ways to arrive at node n-1 from node 0 in the shortest time. Since the answer may be large, return it modulo 10^9 + 7.
//For Optimal Approach, we will use Dijkstra's Algorithm to find the shortest path and count the number of ways to reach each node.
int countPaths(int n,vector<vector<int>>& roads){
    vector<pair<int,int>> adj[n];
    for(auto road:roads){
        adj[road[0]].push_back({road[1],road[2]});
        adj[road[1]].push_back({road[0],road[2]});
    }
    vector<long long> dist(n,1e15);
    vector<int> ways(n,0);
    dist[0]=0;
    ways[0]=1;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,0}); //distance, node
    int mod=1e9+7;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        long long distance=it.first;
        int node=it.second;
        if(distance>dist[node]){
            continue;
        }
        for(auto it:adj[node]){
            int adjNode=it.first;
            int time=it.second;
            if(distance+time<dist[adjNode]){
                dist[adjNode]=distance+time;
                ways[adjNode]=ways[node];
                pq.push({dist[adjNode],adjNode});
            }
            else if(distance+time==dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
} // TC=O(E log V) SC=O(N + E)
int main(){
    int n=7;
    vector<vector<int>> roads={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout<<"Number of ways to arrive at destination: "<<countPaths(n,roads)<<endl;
    return 0;
}