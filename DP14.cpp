#include <iostream>
using namespace std;
//Problem 1: Longest Common Substring
//For Brute Force Approach, we can use two nested loops to generate all possible substrings of both strings and compare them to find the longest common substring.
int longestCommonSubstringBruteForce(string text1,string text2){
    int maxLength=0;
    for(int i=0;i<text1.size();i++){
        for(int j=0;j<text2.size();j++){
            int length=0;
            while(i+length<text1.size() && j+length<text2.size() && text1[i+length]==text2[j+length]){
                length++;
            }
            maxLength=max(maxLength,length);
        }
    }
    return maxLength; 
} // TC=O(M*N*min(M,N)) SC=O(1)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the length of the longest common substring ending at indices i and j of text1 and text2 respectively.
int longestCommonSubstringOptimal(string text1,string text2){
    vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
    int maxLength=0;
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                maxLength=max(maxLength,dp[i][j]);
            }
        }
    }
    return maxLength;
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table.
int longestCommonSubstringSpaceOptimized(string text1,string text2){
    vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);
    int maxLength=0;
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=1+prev[j-1];
                maxLength=max(maxLength,curr[j]);
            }
        else{
            curr[j]=0;
            }
        }       
        prev=curr;
    }
    return maxLength;
} // TC=O(M*N) SC=O(N)
//Problem 2: Longest Palindromic Subsequence
//For Brute Force Approach, we can use recursion to find all possible subsequences of the string and check if they are palindromic to find the longest palindromic subsequence.
int DFS(string s,int i,int j){
    if(i>1){
        return 0;
    }
    if(s[i]==s[j]){
        if(i==j){
            return 1;
        }
        return 2+DFS(s,i+1,j-1);
    }
    return max(DFS(s,i+1,j),DFS(s,i,j-1));
}
int longestPalindromeSubsequenceBruteForce(string s){
    return DFS(s,0,s.size()-1);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(string s,int i,int j,vector<vector<int>>& dp){
    if(i>1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];    
    }
    if(s[i]==s[j]){
        if(i==j){
            dp[i][j]=1;
        }
        else{
            dp[i][j]=2+DFS2(s,i+1,j-1,dp);
        }
    }
    else{
        dp[i][j]=max(DFS2(s,i+1,j,dp),DFS2(s,i,j-1,dp));
    }
    return dp[i][j];
}
int longestPalindromeSubsequenceBetter(string s){
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
    return DFS2(s,0,s.size()-1,dp);
} // TC=O(N*N) SC=O(N*N)+O(N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the length of the longest palindromic subsequence in the substring s[i...j].
int longestPalindromeSubsequenceOptimal(string s){
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    for(int i=s.size()-1;i>=0;i--){
        dp[i][i]=1;
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                dp[i][j]=2+dp[i+1][j-1];    
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }   
        }
    }
    return dp[0][s.size()-1];
} // TC=O(N*N) SC=O(N*N)
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table, but we will need to keep track of the indices to reconstruct the longest palindromic subsequence.
int longestPalindromeSubsequenceSpaceOptimized(string s){
    vector<int> prev(s.size(),0),curr(s.size(),0);
    for(int i=s.size()-1;i>=0;i--){
        curr[i]=1;
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                curr[j]=2+prev[j-1];
            }
            else{
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[s.size()-1];
} // TC=O(N*N) SC=O(N)

int main(){
    string s1="abcjklp",s2="acjkp";
    cout<<longestCommonSubstringBruteForce(s1,s2)<<endl; 
    cout<<longestCommonSubstringOptimal(s1,s2)<<endl;
    cout<<longestCommonSubstringSpaceOptimized(s1,s2)<<endl;
    string s="bbbab";
    cout<<longestPalindromeSubsequenceBruteForce(s)<<endl;
    cout<<longestPalindromeSubsequenceBetter(s)<<endl;
    cout<<longestPalindromeSubsequenceOptimal(s)<<endl;
    cout<<longestPalindromeSubsequenceSpaceOptimized(s)<<endl;
    return 0;
}