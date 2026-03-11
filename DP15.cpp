#include <iostream>
using namespace std;
//Problem 1: Shortest Common Supersequence
//A supersequence of two strings is a string that contains both strings as subsequences. 
//For Brute Force Approach, we can use recursion to find all possible supersequences of the two strings and return the length of the shortest one.
int DFS1(string text1,string text2,int i,int j){
    if(i==text1.size()){
        return text2.size()-j;
    }
    if(j==text2.size()){
        return text1.size()-i;
    }
    if(text1[i]==text2[j]){
        return 1+DFS1(text1,text2,i+1,j+1);
    }
    return 1+min(DFS1(text1,text2,i+1,j),DFS1(text1,text2,i,j+1));
} 
string shortestCommonSupersequenceBruteForce(string text1,string text2){
    string result="";
    int i=0,j=0;
    while(i<text1.size() && j<text2.size()){
        if(text1[i]==text2[j]){
            result+=text1[i];
            i++;
            j++;
        }
        else if(DFS1(text1,text2,i+1,j)<DFS1(text1,text2,i,j+1)){
            result+=text1[i];
            i++;
        }
        else{
            result+=text2[j];
            j++;
        }
    }
    while(i<text1.size()){
        result+=text1[i];
        i++;
    }
    while(j<text2.size()){
        result+=text2[j];
        j++;
    }
    return result;
} // TC=O(2^(M+N)) SC=O(M+N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(string text1,string text2,int i,int j,vector<vector<int>>& dp){
    if(i==text1.size()){
        return text2.size()-j;
    }
    if(j==text2.size()){
        return text1.size()-i;
    }   
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        return dp[i][j]=1+DFS2(text1,text2,i+1,j+1,dp);
    }   
    dp[i][j]=min(1+DFS2(text1,text2,i+1,j,dp),1+DFS2(text1,text2,i,j+1,dp));
    return dp[i][j];
}
string shortestCommonSupersequenceBetter(string text1,string text2){
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
    int length=DFS2(text1,text2,0,0,dp);
    string result="";
    int i=0,j=0;
    while(i<text1.size() && j<text2.size()){
        if(text1[i]==text2[j]){
            result+=text1[i];
            i++;
            j++;
        }
        else if(DFS2(text1,text2,i+1,j,dp)<DFS2(text1,text2,i,j+1,dp)){
            result+=text1[i];
            i++;
        }
        else{
            result+=text2[j];
            j++;
        }
    }
    while(i<text1.size()){
        result+=text1[i];
        i++;
    }
    while(j<text2.size()){
        result+=text2[j];
        j++;
    }
    return result;
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the length of the shortest common supersequence of the substrings text1[0...i-1] and text2[0...j-1].
string shortestCommonSupersequenceOptimal(string text1,string text2){
    vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=0;i<=text1.size();i++){
        for(int j=0;j<=text2.size();j++){
            if(i==0){
                dp[i][j]=j;
            }   
            else if(j==0){
                dp[i][j]=i;
            }
            else if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string result="";
    int i=text1.size(),j=text2.size();
    while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
            result+=text1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]){
            result+=text1[i-1];
            i--;
        }
        else{
            result+=text2[j-1];
            j--;
        }
    }
    while(i>0){
        result+=text1[i-1];
        i--;
    }
    while(j>0){
        result+=text2[j-1];
        j--;
    }   
    reverse(result.begin(),result.end());
    return result;
} // TC=O(M*N) SC=O(M*N)
int main(){
    string text1="AGGTAB",text2="GXTXAYB";
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceBruteForce(text1,text2)<<endl;
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceBetter(text1,text2)<<endl;
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceOptimal(text1,text2)<<endl;
    return 0;
}