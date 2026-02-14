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
int main(){
    string s1="abcjklp",s2="acjkp";
    cout<<longestCommonSubstringBruteForce(s1,s2)<<endl; 
    cout<<longestCommonSubstringOptimal(s1,s2)<<endl;
    cout<<longestCommonSubstringSpaceOptimized(s1,s2)<<endl;
    return 0;
}