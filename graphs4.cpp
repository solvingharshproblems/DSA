#include <iostream>
using namespace std;
//Problem 1: Floor Fill Algorithm
//Given a 2D grid representing an image, a starting pixel, and a new color, perform a "flood fill" to change the color of the starting pixel and all connected pixels
//For Optimal Approach, we will use DFS to traverse all connected pixels and change their color.
void fillDFS(int row,int col,vector<vector<int>>& image,int newColor,int originalColor){
    int n=image.size();
    int m=image[0].size();
    if(row<0 || row>=n || col<0 || col>=m){
        return;
    }
    if(image[row][col]!=originalColor || image[row][col]==newColor){
        return;    
    }
    image[row][col]=newColor;
    fillDFS(row+1,col,image,newColor,originalColor);
    fillDFS(row-1,col,image,newColor,originalColor);
    fillDFS(row,col+1,image,newColor,originalColor);
    fillDFS(row,col-1,image,newColor,originalColor);
}
vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int newColor) {
    int originalColor=image[sr][sc];
    fillDFS(sr,sc,image,newColor,originalColor);
    return image;
} // TC=O(n*m) SC=O(n*m) for storing answers in a matrix + O(n*m) for recursion stack
//Problem 2: Rotten Oranges
//Given a 2D grid representing oranges, where 0=empty cell, 1=fresh orange, 2=rotten orange, find the minimum time required to rot all fresh
//For Optimal Approach, we will declare a queue to store the coordinates of all rotten oranges and time taken to rot adjacent fresh oranges then use BFS to traverse the grid.
int orangesRotting(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    int fresh=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }
            else if(grid[i][j]==1){
                fresh++;
            }
        }
    }
    int time=0;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        q.pop();
        time=max(time,t);
        for(int k=0;k<4;k++){
            int nrow=row+delRow[k];
            int ncol=col+delCol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                grid[nrow][ncol]=2;
                fresh--;
                q.push({{nrow,ncol},t+1});
            }
        }
    }
    if(fresh>0){
        return -1;
    }
    return time;
} // TC=O(n*m) SC= O(n*m) for storing answers in a matrix + O(n*m) for queue
int main(){
    int rows,cols;
    cout<<"Enter the number of rows:";
    cin>>rows;
    cout<<"Enter the number of columns:";
    cin>>cols;
    /*
    vector<vector<int>> image(rows,vector<int>(cols));;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>image[i][j];
        }
    }
    int sr,sc,newColor;
    cout<<"Enter the starting row:";
    cin>>sr;
    cout<<"Enter the starting column:";
    cin>>sc;
    cout<<"Enter the new color:";
    cin>>newColor;
    vector<vector<int>> result=floodFill(image,sr,sc,newColor);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<result[i][j]<<" ";
        }
        cout << endl;
    }
    */
    vector<vector<int>> grid(rows,vector<int>(cols));;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>grid[i][j];
        }
    }
    int time=orangesRotting(grid);
    cout<<"Minimum time to rot all oranges: "<<time<<endl;  
    return 0;
}