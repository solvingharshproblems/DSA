#include <iostream>
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
    int result=numEnclaves(grid);
    cout<<"Number of Enclaves: "<<result<<endl;
    return 0;
}