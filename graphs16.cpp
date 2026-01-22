#include <iostream>
using namespace std;
//Problem 1: Shortest Distance in a Binary Maze
//Given a binary matrix, find the shortest distance from the source cell to the destination cell,
//moving only in 4 possible directions (up, down, left, right) and only through cells with value 1.
//For Optimal Approach, we will apply Dijkstra's Algorithm using a queue instead of a priority queue as all edges have the same weight of 1.
//And a 2-D distance array to keep track of the shortest distance to each cell by initializing all distances to infinity except the source cell which is initialized to 0.
int shortestDistance(vector<vector<int>>& grid,pair<int,int> source,pair<int,int> destination){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[source.first][source.second]=0;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{source.first,source.second}});
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!q.empty()){
        auto it=q.front();
        q.pop();    
        int distance=it.first;
        int row=it.second.first;
        int col=it.second.second;
        for(int i=0;i<4;i++){
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1){
                if(distance+1<dist[newRow][newCol]){
                    dist[newRow][newCol]=distance+1;
                    if(newRow==destination.first && newCol==destination.second){
                        return distance+1;
                    }
                    q.push({dist[newRow][newCol],{newRow,newCol}});
                }
            }
        }
    }
    return -1;
} // TC=O(N*M) SC=O(N*M)
//Problem 2: Path with Minimum Effort in a Grid
//Given a 2D grid of heights, find a path from the top-left to the bottom-right such that the maximum absolute difference in heights between consecutive cells is minimized.
//For Optimal Approach, we will use a modified Dijkstra's Algorithm where we minimize the maximum effort instead of the sum of efforts.
int minEffort(vector<vector<int>>& heights){
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
    effort[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();    
        int currEffort=it.first;
        int row=it.second.first;
        int col=it.second.second;
        for(int i=0;i<4;i++){
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                int nextEffort=max(currEffort,abs(heights[newRow][newCol]-heights[row][col]));
                if(nextEffort<effort[newRow][newCol]){
                    effort[newRow][newCol]=nextEffort;
                    if(newRow==n-1 && newCol==m-1){
                        return nextEffort;
                    }
                    pq.push({nextEffort,{newRow,newCol}});
                }
            }
        }
    }
    return 0;
} // TC=O(N*M log(N*M)) SC=O(N*M)
int main(){
    int n=5,m=5;
    vector<vector<int>> grid={
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 0, 0, 0, 1}
    };
    pair<int,int> source={0,0};
    pair<int,int> destination={4,4};
    int shortestDist=shortestDistance(grid,source,destination);
    if(shortestDist!=-1){
        cout<<"The shortest distance from source to destination is: "<<shortestDist<<endl;
    } 
    else{
        cout<<"The destination is unreachable from the source."<<endl;
    }
    vector<vector<int>> heights={
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };
    int minEffortValue=minEffort(heights);
    cout<<"The minimum effort required to travel from top-left to bottom-right is: "<<minEffortValue<<endl;
    return 0;
}