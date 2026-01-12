#include <iostream>
#include <set>
using namespace std;
//Problem 1: Number of Enclaves
//Given a binary matrix containing 0s and 1s, find the number of 1s that are not connected to the boundary of the matrix.
//For Optimal Approach, we will use BFS to traverse all 1s on the boundary and mark them as visited.
int numEnclaves(vector<vector<int>>& grid){
    int n=grid.size();
    if(n==0) return 0;
    int m=grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1 && !visited[i][j]){
                visited[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    int delRow[]={-1,0,1,0};
                    int delCol[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int nrow=row+delRow[k];
                        int ncol=col+delCol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                            visited[nrow][ncol]=true;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
    }
    int enclaveCount=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                enclaveCount++;
            }
        }
    }
    return enclaveCount;
} // TC=O(n*m) SC=O(n*m) for visited matrix + O(n*m) for queue 
//Problem 2: Number of Distinct Islands
//Two islands are considered to be the same if one island can be translated (not rotated or reflected) to equal the other.
//For Optimal Approach, we will use DFS to explore each island and record its shape relative to its starting point.
void DFS(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited,vector<pair<int,int>>& shape,int baseRow,int baseCol){
    int n=grid.size();
    int m=grid[0].size();
    if(row<0 || row>=n || col<0 || col>=m){
        return;
    }
    if(grid[row][col]==0 || visited[row][col]){
        return;
    }
    visited[row][col]=true;
    shape.push_back({row-baseRow,col-baseCol});
    DFS(row+1,col,grid,visited,shape,baseRow,baseCol);
    DFS(row-1,col,grid,visited,shape,baseRow,baseCol);
    DFS(row,col+1,grid,visited,shape,baseRow,baseCol);
    DFS(row,col-1,grid,visited,shape,baseRow,baseCol);
}
int distinctIslands(vector<vector<int>>& grid){
    int n=grid.size();
    if(n==0) return 0;
    int m=grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    set<vector<pair<int,int>>> islandShapes;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                vector<pair<int,int>> shape;
                DFS(i,j,grid,visited,shape,i,j);
                islandShapes.insert(shape);
            }
        }
    }
    return islandShapes.size();
} // TC=O(n*m) SC=O(n*m) for visited matrix + O(k*l) for set where k is number of islands and l is average size of island
int main(){
    int v=4,e=4;
    vector<vector<int>> graph(v);
    cout<<"Enter the edges (u v) of the graph:"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    vector<vector<int>> grid={
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    /*
    int result=numEnclaves(grid);
    cout<<"Number of Enclaves: "<<result<<endl;
    */
    int result=distinctIslands(grid);
    cout<<"Number of Distinct Islands: "<<result<<endl;
    return 0;
}