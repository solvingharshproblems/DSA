#include <iostream>
using namespace std;
//Problem 1: Longest Common Subsequence
//Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
//For Brute Force Approach, we can use recursion to find all possible subsequences of both strings and compare them to find the longest common subsequence. 
int DFS(string text1,string text2,int i,int j){
    if(i==text1.size() || j==text2.size()){
        return 0;
    }
    if(text1[i]==text2[j]){
        return 1+DFS(text1,text2,i+1,j+1);
    }
    return max(DFS(text1,text2,i+1,j),DFS(text1,text2,i,j+1));
}
int longestCommonSubsequenceBruteForce(string text1,string text2){
    return DFS(text1,text2,0,0);
} // TC=O(2^(M+N)) SC=O(M+N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(string text1,string text2,int i,int j,vector<vector<int>>& dp){
    if(i==text1.size() || j==text2.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        dp[i][j]=1+DFS2(text1,text2,i+1,j+1,dp);
    } 
    else{
        dp[i][j]=max(DFS2(text1,text2,i+1,j,dp),DFS2(text1,text2,i,j+1,dp));
    }
    return dp[i][j];
}
int longestCommonSubsequenceBetter(string text1,string text2){
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
    return DFS2(text1,text2,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the length of the longest common subsequence of the substrings text1[0...i-1] and text2[0...j-1].
int longestCommonSubsequenceOptimal(string text1,string text2){
    vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table.
int longestCommonSubsequenceSpaceOptimized(string text1,string text2){
    vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
            curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[text2.size()];
} // TC=O(M*N) SC=O(N)
//Problem 2: Print Longest Common Subsequence
//Given two strings text1 and text2, return the longest common subsequence of text1 and text2. If there is no common subsequence, return an empty string "".
//For Optimal Approach, we will use the same dp table as in the previous problem to reconstruct the longest common subsequence by backtracking through the table.
string LCSPrintOptimal(string text1,string text2){
    vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=text1.size(),j=text2.size();
    string ans="";
    while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
            ans+=text1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will optimize the space by using two 1D arrays to store the results of the previous and current rows of the dp table, but we will need to keep track of the indices to reconstruct the longest common subsequence.
string LCSPrintSpaceOptimized(string text1,string text2){
    vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
            curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    int i=text1.size(),j=text2.size();
    string ans="";
    while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
            ans+=text1[i-1];
            i--;
            j--;
        }
        else if(prev[j]>curr[j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
} // TC=O(M*N) SC=O(N)
int main(){
    string text1="abcde";
    string text2="ace";
    cout<<longestCommonSubsequenceBruteForce(text1,text2)<<endl;
    cout<<longestCommonSubsequenceBetter(text1,text2)<<endl;
    cout<<longestCommonSubsequenceOptimal(text1,text2)<<endl;
    cout<<longestCommonSubsequenceSpaceOptimized(text1,text2)<<endl;
    cout<<LCSPrintOptimal(text1,text2)<<endl;
    cout<<LCSPrintSpaceOptimized(text1,text2)<<endl;
    return 0;
}