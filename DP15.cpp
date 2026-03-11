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
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table, but we will need to keep track of the indices to reconstruct the shortest common supersequence.
string shortestCommonSupersequenceSpaceOptimized(string text1,string text2){    
    vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);
    for(int i=0;i<=text1.size();i++){
        for(int j=0;j<=text2.size();j++){
            if(i==0){
                curr[j]=j;
            }   
            else if(j==0){
                curr[j]=i;
            }
            else if(text1[i-1]==text2[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
                curr[j]=1+min(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    string result="";
    int i=text1.size(),j=text2.size();
    while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
            result+=text1[i-1];
            i--;
            j--;
        }
        else if(prev[j]<curr[j-1]){
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
} // TC=O(M*N) SC=O(N)
//Problem 2: Distinct Subsequences
//Return the number of times the string text2 occurs as a subsequence in text1.
//For Brute Force Approach, we can use recursion to find all possible subsequences of text1 and check if they are equal to text2 to count the number of occurrences.
int DFS3(string text1,string text2,int i,int j){
    if(j==text2.size()){
        return 1;
    }
    if(i==text1.size()){
        return 0;
    }               
    if(text1[i]==text2[j]){
        return DFS3(text1,text2,i+1,j+1)+DFS3(text1,text2,i+1,j);
    }
    return DFS3(text1,text2,i+1,j);
}
int distinctSubsequencesBruteForce(string text1,string text2){
    return DFS3(text1,text2,0,0);
} // TC=O(2^M) SC=O(M)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS4(string text1,string text2,int i,int j,vector<vector<int>>& dp){
    if(j==text2.size()){
        return 1;
    }
    if(i==text1.size()){
        return 0;
    }   
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        dp[i][j]=DFS4(text1,text2,i+1,j+1,dp)+DFS4(text1,text2,i+1,j,dp);
    }
    else{
        dp[i][j]=DFS4(text1,text2,i+1,j,dp);
    }
    return dp[i][j];
}
int distinctSubsequencesBetter(string text1,string text2){
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
    return DFS4(text1,text2,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the number of times the substring text2[0...j-1] occurs as a subsequence in text1[0...i-1].
int distinctSubsequencesOptimal(string text1,string text2){
    vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=0;i<=text1.size();i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=text2.size();j++){   
        dp[0][j]=0;
    }
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[text1.size()][text2.size()];
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table, but we will need to keep track of the indices to reconstruct the number of occurrences.
int distinctSubsequencesSpaceOptimized(string text1,string text2){
    vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);
    prev[0]=1;
    for(int i=1;i<=text1.size();i++){
        curr[0]=1;  
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=prev[j-1]+prev[j];
            }
            else{
                curr[j]=prev[j];
            }
        }
        prev=curr;
    }
    return prev[text2.size()];
} // TC=O(M*N) SC=O(N)
int main(){
    string text1="AGGTAB",text2="GXTXAYB";
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceBruteForce(text1,text2)<<endl;
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceBetter(text1,text2)<<endl;
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceOptimal(text1,text2)<<endl;
    cout<<"Shortest Common Supersequence of "<<text1<<" and "<<text2<<" is: "<<shortestCommonSupersequenceSpaceOptimized(text1,text2)<<endl;
    string text3="rabbbit",text4="rabbit";
    cout<<"Number of times "<<text4<<" occurs as a subsequence in "<<text3<<" is: "<<distinctSubsequencesBruteForce(text3,text4)<<endl;
    cout<<"Number of times "<<text4<<" occurs as a subsequence in "<<text3<<" is: "<<distinctSubsequencesBetter(text3,text4)<<endl;
    cout<<"Number of times "<<text4<<" occurs as a subsequence in "<<text3<<" is: "<<distinctSubsequencesOptimal(text3,text4)<<endl;
    cout<<"Number of times "<<text4<<" occurs as a subsequence in "<<text3<<" is: "<<distinctSubsequencesSpaceOptimized(text3,text4)<<endl;
    return 0;
}