#include <iostream>
using namespace std;
//Problem 1: Prim's Algorithm for Minimum Spanning Tree
//You are given a connected, undirected graph represented as an adjacency matrix. The task is to find the Minimum Spanning Tree (MST) of the graph using Prim's Algorithm.
//Prim's Algorithm is a greedy algorithm that builds the MST by starting from an arbitrary vertex and repeatedly adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.
//For the implementation, we will use a priority queue to efficiently get the minimum weight edge at each step and a boolean array to keep track of vertices included in the MST.
int primMST(vector<vector<int>>& graph){
    int n=graph.size();
    vector<bool> inMST(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0}); // {weight, vertex}
    int totalWeight=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(inMST[it.second]) continue;
        inMST[it.second]=true;
        totalWeight+=it.first;
        for(int v=0;v<n;v++){
            if(graph[it.second][v]!=-1 && !inMST[v]){
                pq.push({graph[it.second][v],v});
            }
        }
    }
    return totalWeight;
} // TC=O(E log V) SC=O(V)
//Problem 2: Disjoint Set 
//Disjoint Set (also known as Union-Find) is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets. It supports two main operations: Find and Union.
//Find: Determine which subset a particular element is in. This can be used to determine if two elements are in the same subset.
//Union: Join two subsets into a single subset.
//We will implement the Disjoint Set with two optimizations: Union by Rank and Union by Size to ensure efficient operations. 
//Union by Rank ensures that the smaller tree is always added under the root of the larger tree, keeping the overall tree flat.
//Union by Size ensures that the smaller set is always added under the root of the larger set.
class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
}; // TC=O(4*alpha) SC=O(N) where alpha is the Inverse Ackermann Function which is near about constant time.
int main(){
    int n=5;
    vector<vector<int>> graph={
        {0,2,-1,6,-1},
        {2,0,3,8,5},
        {-1,3,0,-1,7},
        {6,8,-1,0,9},
        {-1,5,7,9,0}
    };  
    cout<<"Total weight of MST is: "<<primMST(graph)<<endl;
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"3 and 7 are in the same set."<<endl;
    }
    else{
        cout<<"3 and 7 are in different sets."<<endl;
    }

    ds.unionBySize(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"3 and 7 are in the same set."<<endl;
    }
    else{
        cout<<"3 and 7 are in different sets."<<endl;
    }
    return 0;
}