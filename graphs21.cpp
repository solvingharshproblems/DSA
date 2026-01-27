#include <iostream>
using namespace std;
//Problem 1: Kruskal's Algorithm for Minimum Spanning Tree
//You are given a connected, undirected graph represented as an edge list. The task is to find the Minimum Spanning Tree (MST) of the graph using Kruskal's Algorithm
//In this algorithm, firstly you need to sort all the edges according to the weight in increasing order. 
//Then, you need to iterate through the sorted edges and add them to the MST if they do not form a cycle.
//For Optimal Approach, we will use the Disjoint Set (Union-Find) data structure to efficiently check for cycles while adding edges to the MST.

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
};
int kruskalMST(int n,vector<vector<int>>& edges){
    vector<pair<int,pair<int,int>>> edgeList;
    for(auto it:edges){
        int weight=it[0];
        int u=it[1];
        int v=it[2];
        edgeList.push_back({weight,{u,v}});
    }    
    DisjointSet ds(n);
    sort(edgeList.begin(),edgeList.end());
    int mstWeight=0;
    for(auto it:edgeList){
        int weight=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            mstWeight+=weight;
            ds.unionBySize(u,v);
        }
    }
    return mstWeight;
} // TC=O(E log E + E * alpha(V)) SC=O(V)
//Problem 2: Number of Provinces
//A province is a group of directly or indirectly connected cities and non other cities outside of the group.
//For Optimal Approach, we will use Disjoint Set (Union-Find) data structure to find the number of connected components in the graph.
int numProvinces(int n,vector<vector<int>>& isConnected){
    DisjointSet ds(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                ds.unionBySize(i+1,j+1);
            }
        }
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(ds.findUPar(i)==i){
            count++;    
        }
    }
    return count;
} // TC=O(N^2 * alpha(N)) SC=O(N)
int main(){
    int n=6;
    vector<vector<int>> edges={
        {1,1,4},
        {2,1,2},
        {3,2,3},
        {3,2,4},
        {4,1,5},
        {5,3,4},
        {7,2,6},
        {8,3,6},
        {9,4,5}
    };
    cout<<"Minimum Spanning Tree weight: "<<kruskalMST(n,edges)<<endl;
    int m=3;
    vector<vector<int>> isConnected={
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout<<"Number of Provinces: "<<numProvinces(m,isConnected)<<endl;
    return 0;
}