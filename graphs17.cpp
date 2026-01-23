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
//Problem 2: Minimum Multiplications to reach End Number
//Given a start number, an end number, and a set of multipliers, find the minimum number of multiplications needed to reach the end number from the start number using the given multipliers.
//Note: If your number exceeds 100000, take modulo 100000 after each multiplication.
//For Optimal Approach, we will use Dijkstra's Algorithm with a queue to explore all possible multiplications while keeping track of the minimum steps to reach each number.
int minMultiplications(int start,int end,vector<int>& multipliers){
    vector<int> dist(100000,INT_MAX);
    dist[start]=0;
    queue<pair<int,int>> q;
    q.push({0,start}); //steps, number
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int steps=it.first;
        int number=it.second;
        if(number==end){
            continue;
        }
        for(auto multiplier:multipliers){
            int newNumber=(number*multiplier)%100000;
            if(steps+1<dist[newNumber]){
                dist[newNumber]=steps+1;
                q.push({steps+1,newNumber});
            }
        }
    }
    return dist[end]==INT_MAX?-1:dist[end];
} // TC=O(M*100000) SC=O(100000)
int main(){
    int n=3;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{0,2,500}};
    int src=0;
    int dst=2;
    int k=1;
    cout<<findCheapestPrice(n,flights,src,dst,k)<<endl;
    int start=2;
    int end=12;
    vector<int> multipliers={2,3,5};
    cout<<minMultiplications(start,end,multipliers)<<endl;  
    return 0;
}