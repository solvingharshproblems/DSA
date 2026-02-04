#include <iostream>
using namespace std;
//Problem 1: Ninja's Training
//A ninja is planning his training schedule over a series of days.
//Each day, he can perform one of three activities: Running, Fighting Practice, or Learning New Moves.
//However, he cannot perform the same activity on two consecutive days.
//The goal is to maximize the total merit points earned over the training period.
//For Brute Force Approach, we can use recursion to explore all possible activity sequences.
int DFS(vector<vector<int>>& points,int day,int index){
    if(day==0){
        int maxInPoints=0;
        for(int i=0;i<=2;i++){
            if(i!=index){
                maxInPoints=max(maxInPoints,points[0][i]);
            }
        }
        return maxInPoints;
    }
    int maxInPoints=0;
    for(int i=0;i<=2;i++){
        if(i!=index){
            int point=points[day][i]+DFS(points,day-1,i);
            maxInPoints=max(maxInPoints,point);
        }
    }
    return maxInPoints;
}
int ninjaTrainingBruteForce(vector<vector<int>>& points){
    int n=points.size();
    return DFS(points,n-1,3);
} // TC=O(3^N) SC=O(N)
//For Better Approach, we can use tabulation to store the computed maximum merit points up to each day for each last activity.
int ninjaTrainingBetter(vector<vector<int>>& points){
    int n=points.size();
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        for(int last=0;last<=3;last++){
            dp[day][last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
} // TC=O(N*4*3) SC=O(N*4)
//For Optimal Approach, we will use space optimization to reduce the space complexity.
int ninjaTrainingOptimal(vector<vector<int>>& points){
    int n=points.size();
    vector<int> prev(4,0);      
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int> curr(4,0);  
        for(int last=0;last<=3;last++){
            curr[last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    int point=points[day][task]+prev[task];
                    curr[last]=max(curr[last],point);
                }
            }
        }
        prev=curr;
    }
    return prev[3];
} // TC=O(N*4*3) SC=O(4)
//Problem 2: Grid Unique Paths
//A robot is located at the top-left corner of a m x n grid (marked 'Start').
//The robot can only move either down or right at any point in time.
//The robot is trying to reach the bottom-right corner of the grid (marked 'Finish').
//How many possible unique paths are there?
//For Brute Force Approach, we can use recursion to explore all possible paths from the start to the finish.
int DFS2(int n,int m,int i,int j){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    return DFS2(n,m,i+1,j)+DFS2(n,m,i,j+1);
}
int uniquePathsBruteForce(int m,int n){
    return DFS2(n,m,0,0);
} // TC=O(2^(M+N)) SC=O(M+N)
//For Better Approach, we can use memoization to store the computed number of unique paths to each cell.
int DFS3(int m,int n,int i,int j,vector<vector<int>>& dp){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=DFS3(m,n,i+1,j,dp)+DFS3(m,n,i,j+1,dp);
    return dp[i][j];
}
int uniquePathsBetter(int m,int n){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return DFS3(m,n,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to iteratively compute the number of unique paths to each cell.
//Note: Steps to convert memoization to tabulation:
//1. Declare base cases
//2. Express all states in terms of loops
//3. Copy the recurrence relation
int uniquePathsOptimal(int m,int n){
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{   
                int up=0;
                int left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
} // TC=O(M*N) SC=O(M*N)
int main(){
    int n;
    cout<<"Enter number of days: ";
    cin>>n;
    vector<vector<int>> points(n);
    cout<<"Enter merit points for each activity on each day:\n";
    for(int i=0;i<n;i++){
        points[i].resize(3);
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }
    cout<<ninjaTrainingBruteForce(points)<<endl;
    cout<<ninjaTrainingBetter(points)<<endl;
    cout<<ninjaTrainingOptimal(points)<<endl;
    int x=4, y=3;
    cout<<"Number of unique paths in a "<<x<<"x"<<y<<" grid: "<<uniquePathsBruteForce(x,y)<<endl;
    cout<<"Number of unique paths in a "<<x<<"x"<<y<<" grid: "<<uniquePathsBetter(x,y)<<endl;
    cout<<"Number of unique paths in a "<<x<<"x"<<y<<" grid: "<<uniquePathsOptimal(x,y)<<endl;
    return 0;
}