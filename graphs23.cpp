#include <iostream>
#include <unordered_set>
using namespace std;
//Problem 1: Making a large Island
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. Return the size of the largest island in grid after applying this operation. An island is a 4-directionally connected group of 1s.
//For Optimal Approach, we will use Disjoint Set (Union-Find) data structure to dynamically manage the connected components as we change 0s to 1s.
class DisjointSet{
public:
    vector<int> rank,parent,size;
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
int largestIsland(vector<vector<int>>& grid){
    int n=grid.size();
    DisjointSet ds(n*n);
    vector<vector<int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1){
                for(auto dir:directions){
                    int nRow=row+dir[0];
                    int nCol=col+dir[1];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && grid[nRow][nCol]==1){
                        int node=row*n+col;
                        int adjNode=nRow*n+nCol;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
    }
    int maxIslandSize=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==0){
                unordered_set<int> components;
                for(auto dir:directions){
                    int nRow=row+dir[0];
                    int nCol=col+dir[1];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && grid[nRow][nCol]==1){
                        int adjNode=nRow*n+nCol;
                        components.insert(ds.findUPar(adjNode));
                    }
                }
                int islandSize=1;
                for(auto it:components){
                    islandSize+=ds.size[it];
                }
                maxIslandSize=max(maxIslandSize,islandSize);
            }
        }
    }
    for(int cell=0;cell<n*n;cell++){
        maxIslandSize=max(maxIslandSize,ds.size[ds.findUPar(cell)]);
    }
    return maxIslandSize;
} // TC=O(N*N * alpha(N*N)) SC=O(N*N) where N is the size of the grid.
//Problem 2: Most Stones Removed with Same Row or Column
//You are given an array stones where stones[i] = [xi, yi] represents the location of the ith stone. A stone can be removed if it shares either the same row or the same column as another stone that has not been removed. Return the largest possible number of stones that can be removed.
//For Optimal Approach, we will use Disjoint Set (Union-Find) data structure to dynamically manage the connected components as we remove stones.
int removeStones(vector<vector<int>>& stones){
    int n=stones.size();
    DisjointSet ds(2*n);
    for(auto stone:stones){
        int row=stone[0];
        int col=stone[1]+n; 
        ds.unionBySize(row,col);
    }
    unordered_set<int> uniqueParents;
    for(int i=0;i<n;i++){
        int parent=ds.findUPar(stones[i][0]);
        uniqueParents.insert(parent);
    }
    return n-uniqueParents.size();
} // TC=O(N * alpha(2N)) SC=O(2N) where N is the number of stones.
int main(){
    int n=5;
    vector<vector<int>> grid={
        {1,0,1,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {1,1,0,1,1},
        {0,0,1,1,0}
    };
    cout<<largestIsland(grid)<<endl;
    vector<vector<int>> stones={
        {0,0},
        {0,1},
        {1,0},
        {1,2},
        {2,1},
        {2,2}
    };
    cout<<removeStones(stones)<<endl;
    return 0;
}