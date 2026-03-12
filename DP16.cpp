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
//Problem 2: Wildcard Matching
//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
//Note: Pattern will only be present in string p and not in string s.
//For Brute Force Approach, we can use recursion to find all possible combinations of matches and return true if a match is found, otherwise return false.
bool DFS3(string s,string p,int i,int j){
    if(i==s.size() && j==p.size()){
        return true;
    }
    if(j==p.size()){
        return false;
    }
    if(p[j]=='*'){
        return DFS3(s,p,i,j+1) || (i<s.size() && DFS3(s,p,i+1,j));
    }
    if(i<s.size() && (s[i]==p[j] || p[j]=='?')){
        return DFS3(s,p,i+1,j+1);
    }
    return false;
}
bool wildcardMatchingBruteForce(string s,string p){
    return DFS3(s,p,0,0);
} // TC=O(2^(M+N)) SC=O(M+N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
bool DFS4(string s,string p,int i,int j,vector<vector<int>>& dp){
    if(i==s.size() && j==p.size()){
        return true;
    }
    if(j==p.size()){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(p[j]=='*'){
        dp[i][j]=DFS4(s,p,i,j+1,dp) || (i<s.size() && DFS4(s,p,i+1,j,dp));
        return dp[i][j];
    }
    if(i<s.size() && (s[i]==p[j] || p[j]=='?')){
        dp[i][j]=DFS4(s,p,i+1,j+1,dp);
        return dp[i][j];
    }
    dp[i][j]=false;
    return dp[i][j];
}
bool wildcardMatchingBetter(string s,string p){
    vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
    return DFS4(s,p,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents whether the substring s[0...i-1] matches the substring p[0...j-1].
bool wildcardMatchingOptimal(string s,string p){
    vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
    dp[0][0]=true;
    for(int j=1;j<=p.size();j++){
        if(p[j-1]=='*'){
            dp[0][j]=dp[0][j-1];
        }
    }
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=p.size();j++){
            if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-1] || dp[i-1][j];
            }
            else if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
        }
    }
    return dp[s.size()][p.size()];
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will use two 1D arrays to store the results of the previous and current rows of the dp table.
bool wildcardMatchingSpaceOptimized(string s,string p){
    vector<bool> prev(p.size()+1,false),curr(p.size()+1,false);
    prev[0]=true;
    for(int j=1;j<=p.size();j++){
        if(p[j-1]=='*'){
            prev[j]=prev[j-1];
        }
    }
    for(int i=1;i<=s.size();i++){
        curr[0]=false;
        for(int j=1;j<=p.size();j++){
            if(p[j-1]=='*'){
                curr[j]=curr[j-1] || prev[j];
            }
            else if(s[i-1]==p[j-1] || p[j-1]=='?'){
                curr[j]=prev[j-1];
            }
        }
        prev=curr;
    }
    return prev[p.size()];
} // TC=O(M*N) SC=O(N)
int main(){
    string word1="horse",word2="ros";
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceBruteForce(word1,word2)<<endl;
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceBetter(word1,word2)<<endl;
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceOptimal(word1,word2)<<endl;
    cout<<"Minimum number of operations required to convert "<<word1<<" to "<<word2<<": "<<editDistanceSpaceOptimized(word1,word2)<<endl;
    string s="adceb",p="*a*b";
    if(wildcardMatchingBruteForce(s,p)){
        cout<<"The string "<<s<<" matches the pattern "<<p<<endl;
    }
    else{
        cout<<"The string "<<s<<" does not match the pattern "<<p<<endl;
    }
    if(wildcardMatchingBetter(s,p)){
        cout<<"The string "<<s<<" matches the pattern "<<p<<endl;
    }
    else{
        cout<<"The string "<<s<<" does not match the pattern "<<p<<endl;
    }
    if(wildcardMatchingOptimal(s,p)){
        cout<<"The string "<<s<<" matches the pattern "<<p<<endl;
    }
    else{
        cout<<"The string "<<s<<" does not match the pattern "<<p<<endl;
    }
    if(wildcardMatchingSpaceOptimized(s,p)){
        cout<<"The string "<<s<<" matches the pattern "<<p<<endl;
    }
    else{
        cout<<"The string "<<s<<" does not match the pattern "<<p<<endl;
    }
    return 0;
}