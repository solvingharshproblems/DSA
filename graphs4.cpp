#include <iostream>
using namespace std;
//Problem 1: Floor Fill Algorithm
//Given a 2D grid representing an image, a starting pixel, and a new color, perform a "flood fill" to change the color of the starting pixel and all connected pixels
//For Optimal Approach, we can use DFS to traverse all connected pixels and change their color.
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
int main(){
    int rows,cols;
    cout<<"Enter the number of rows:";
    cin>>rows;
    cout<<"Enter the number of columns:";
    cin>>cols;
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
    return 0;
}