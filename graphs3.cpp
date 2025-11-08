#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Number of Provinces
//Given an adjacency matrix representing connections between cities, find the number of provinces (connected components) in the graph.
//For Optimal Approach, we can use either BFS or DFS to traverse the graph and count the number of connected components.
void DFS(int v,vector<int> graph[],vector<int> visited){
    visited[v]=1;
    for(auto it:graph[v]){
        if(!visited[it]){
            DFS(it,graph,visited);
        }
    }
}
int Provinces(int v,vector<vector<int>>& isConnected){
    vector<int> adj[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> visited(v,0);
    int count=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            count++;
            DFS(i,adj,visited);
        }
    }
    return count;
} // TC=O(v+2e) SC=O(v+2e)+O(v)
//Problem 2: Number of Islands
//Given a 2D matrix consisting of 0s (water) and 1s (land), find the number of islands (connected components of 1s).
//For Optimal Approach, we will declare a queue named starting point storing the coordinates of each cell in the grid and use BFS to traverse all connected land cells.
void BFS(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &grid){
    visited[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});
    int delRow[]={-1,-1,-1,0,1,1,1,0};
    int delCol[]={-1,0,1,1,1,0,-1,-1};
    while(!q.empty()){
        row=q.front().first;
        col=q.front().second;
        q.pop();
        for(int k=0;k<8;k++){
            int nrow=row+delRow[k];
            int ncol=col+delCol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}
int Islands(vector<vector<char>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                count++;
                BFS(i,j,visited,grid);
            }
        }
    }
    return count;
} // TC=O(n*m) SC=O(n*m)+O(n*m)
int main(){
    int v=3;
    vector<vector<int>> isConnected={{1,1,0},{1,1,0},{0,0,1}};
    int result=Provinces(v,isConnected);
    cout<<"Number of Provinces: "<<result<<endl;
    vector<vector<char>> grid={{'0','1','1','0'},{'0','1','1','0'},{'0','0','1','0'},{'0','0','0','0'},{'1','1','0','1'}};
    int result2=Islands(grid);
    cout<<"Number of Islands: "<<result2<<endl;
    return 0;
}