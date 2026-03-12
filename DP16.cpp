#include <iostream>
using namespace std;
//Problem 1: Edit Distance
//You are given two strings word1 and word2. You want to convert word1 to word2 using the following operations:
//Insert a character Delete a character Replace a character
//Return the minimum number of operations required to convert word1 to word2.
//For Brute Force Approach, we can use recursion to find all possible combinations of operations and return the minimum number of operations required to convert word1 to word2.
int DFS1(string word1,string word2,int i,int j){
    if(i==word1.size()){
        return word2.size()-j;
    }
    if(j==word2.size()){
        return word1.size()-i;
    }
    if(word1[i]==word2[j]){
        return DFS1(word1,word2,i+1,j+1);
    }
    return 1+min(DFS1(word1,word2,i+1,j),min(DFS1(word1,word2,i,j+1),DFS1(word1,word2,i+1,j+1)));
}
int editDistanceBruteForce(string word1,string word2){
    return DFS1(word1,word2,0,0);
} // TC=O(3^(M+N)) SC=O(M+N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(string word1,string word2,int i,int j,vector<vector<int>>& dp){
    if(i==word1.size()){
        return word2.size()-j;
    }
    if(j==word2.size()){
        return word1.size()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(word1[i]==word2[j]){
        dp[i][j]=DFS2(word1,word2,i+1,j+1,dp);
        return dp[i][j];
    }
    dp[i][j]=1+min(DFS2(word1,word2,i+1,j,dp),min(DFS2(word1,word2,i,j+1,dp),DFS2(word1,word2,i+1,j+1,dp)));
    return dp[i][j];
}
int editDistanceBetter(string word1,string word2){
    vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
    return DFS2(word1,word2,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the minimum number of operations required to convert the substring word1[0...i-1] to the substring word2[0...j-1].
int editDistanceOptimal(string word1,string word2){
    vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
    for(int i=0;i<=word1.size();i++){
        for(int j=0;j<=word2.size();j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[word1.size()][word2.size()];
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will use two 1D arrays to store the results of the previous and current rows of the dp table.
int editDistanceSpaceOptimized(string word1,string word2){
    vector<int> prev(word2.size()+1,0),curr(word2.size()+1,0);
    for(int i=0;i<=word1.size();i++){
        for(int j=0;j<=word2.size();j++){
            if(i==0){
                curr[j]=j;
            }
            else if(j==0){
                curr[j]=i;
            }
            else if(word1[i-1]==word2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
            }
        }
        prev=curr;
    }
    return prev[word2.size()];
} // TC=O(M*N) SC=O(N)
int main(){
    string word1="horse",word2="ros";
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceBruteForce(word1,word2)<<endl;
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceBetter(word1,word2)<<endl;
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceOptimal(word1,word2)<<endl;
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceSpaceOptimized(word1,word2)<<endl;
    return 0;
}