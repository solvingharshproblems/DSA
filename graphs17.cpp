#include <iostream>
using namespace std;
//Problem 1: Cheapest Flight Within K Stops
//Given a list of flights represented as (source, destination, price), find the cheapest price from a starting city to a destination city with at most K stops.
//For Optimal Approach, we will use a modified Dijkstra's Algorithm with a priority queue storing stops,node and cost.And we will maintain a stops array to keep track of the minimum cost to reach each node within the allowed stops.
int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k){
    vector<pair<int,int>> adj[n];
    for(auto flight:flights){
        adj[flight[0]].push_back({flight[1],flight[2]});
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}}); //cost, {node, stops}
    vector<int> stops(n,INT_MAX);
    stops[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stop=it.first;
        int node=it.second.first;
        int cost=it.second.second;
        if(stop>k){
            continue;
        }
        for(auto it:adj[node]){
            int adjNode=it.first;
            int price=it.second;
            if(cost+price<stops[adjNode] && stop<=k){
                stops[adjNode]=cost+price;
                q.push({stop+1,{adjNode,cost+price}});
            }
        }
    }
    if(stops[dst]==INT_MAX){
        return -1;
    }
    return stops[dst];
} // TC=O(N + E*K) SC=O(N + E)
int main(){
    int n=3;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{0,2,500}};
    int src=0;
    int dst=2;
    int k=1;
    cout<<findCheapestPrice(n,flights,src,dst,k)<<endl;
    return 0;
}