#include <iostream>
using namespace std;
//Problem 1: 0/1 Matrix
//Given a binary matrix, we need to find the distance of the nearest 0 for each cell.
//For Optimal Approach, we will declare a queue to store the coordinates of all 0s and their distance from themselves (0) then use BFS to traverse the matrix and update the distance of
vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dist(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                visited[i][j]=true;
            }
        }
    }
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int d=q.front().second;
        q.pop();
        dist[row][col]=d;
        for(int k=0;k<4;k++){
            int nrow=row+delRow[k];
            int ncol=col+delCol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){
                visited[nrow][ncol]=true;
                q.push({{nrow,ncol},d+1});
            }
        }
    }
    return dist;
} // TC=O(n*m) SC=O(n*m) for distance matrix + O(n*m) for visited matrix + O(n*m) for queue
int main(){
    int n,m;
    cout<<"Enter the number of rows:";
    cin>>n;
    cout<<"Enter the number of columns:";
    cin>>m;
    vector<vector<int>> mat(n,vector<int>(m));;
    cout<<"Enter the elements of the matrix (0s and 1s):"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> result=updateMatrix(mat);
    cout<<"The distance matrix is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}