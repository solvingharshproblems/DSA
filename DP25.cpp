#include <iostream>
using namespace std;
//Problem 1: Partition Array For Maximum Sum
//Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
//After partitioning, each subarray has their values changed to become the maximum value of that subarray. 
//The partitioning should be done in a way that maximizes the sum of the given array after partitioning. Return the maximum sum of the given array after partitioning.
//For Brute Force Approach, we can use recursion to find all possible combinations of partitioning the array and return the maximum sum of those combinations.
int DFS1(vector<int>& arr,int i,int k){
    if(i>=arr.size()){
        return 0;
    }
    int maxVal=INT_MIN,res=0;
    for(int j=i;j<min(i+k,(int)arr.size());j++){
        maxVal=max(maxVal,arr[j]);
        res=max(res,maxVal*(j-i+1)+DFS1(arr,j+1,k));
    }
    return res;
}
int maxSumAfterPartitioningBruteForce(vector<int>& arr, int k) {
    int n=arr.size();
    return DFS1(arr,0,k);
} //TC=O(N^K) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(vector<int>& arr,int i,int k,vector<int> &dp){
    if(i>=arr.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int maxVal=INT_MIN,res=0;
    for(int j=i;j<min(i+k,(int)arr.size());j++){
        maxVal=max(maxVal,arr[j]);
        res=max(res,maxVal*(j-i+1)+DFS2(arr,j+1,k,dp));
    }
    return dp[i]=res;
}
int maxSumAfterPartitioningBetter(vector<int>& arr, int k) {
    int n=arr.size();
    vector<int> dp(n,-1);
    return DFS2(arr,0,k,dp);
} //TC=O(N*K) SC=O(N)+O(N)
//For Optimal Approach, we will use tabulation to fill a dp array iteratively based on the results of smaller subproblems.
int maxSumAfterPartitioningOptimal(vector<int>& arr,int k){
    int n=arr.size();
    vector<int> dp(n,0);
    for(int i=n-1;i>=0;i--){
        int maxVal=INT_MIN,res=0;
        for(int j=i;j<min(i+k,n);j++){
            maxVal=max(maxVal,arr[j]);
            int currentSum=maxVal*(j-i+1);
            if(j+1<n){
                currentSum+=dp[j+1];
            }
            res=max(res,currentSum);
        }
        dp[i]=res;
    }
    return dp[0];
} //TC=O(N*K) SC=O(N)
//Problem 2: Maximum Rectangle Area with all 1's in a Binary Matrix
//For Optimal Approach, we will use largest rectangle in histogram approach for each row of the matrix to find the maximum rectangle area with all 1's in the binary matrix.
int largestRectangleInHistogramOptimal(vector<int>& arr){
    stack<int> s;
    int n=arr.size();
    int maxArea=0;
    for(int i=0;i<=n;i++){
        while(!s.empty() && (i==n || arr[s.top()]>=(i<n ? arr[i]:0))){
           int height=arr[s.top()];
            s.pop();
            int width;
            if(s.empty()){
                width=i; 
            }
            else{
                width=i-s.top()-1;
            }
            maxArea=max(maxArea,height*width);
        }
        s.push(i);
    }
    return maxArea;
}
int maximalRectangleOptimal(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()){
        return 0;
    }
    int n=matrix.size();
    int m=matrix[0].size();
    int maxArea=0;
    vector<vector<int>> prefixSum(n, vector<int>(m,0));
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            int val=matrix[i][j]-'0';
            sum+=val;
            if(val==0){
                sum=0;
            }
            prefixSum[i][j]=sum;
        }
    }
    for(int i=0;i<n;i++){
        maxArea=max(maxArea,largestRectangleInHistogramOptimal(prefixSum[i]));
    }
    return maxArea;
} //TC=O(M*N) SC=O(M*N)
int main(){
    int n=7;
    vector<int> arr={1,15,7,9,2,5,10};
    int k=3;
    cout<<maxSumAfterPartitioningBruteForce(arr,k)<<endl;
    cout<<maxSumAfterPartitioningBetter(arr,k)<<endl;
    cout<<maxSumAfterPartitioningOptimal(arr,k)<<endl;
    vector<vector<char>> matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalRectangleOptimal(matrix)<<endl;
    return 0;
}