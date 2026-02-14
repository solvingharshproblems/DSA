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
//Problem 3: Minimum Insertions to Make String Palindrome
//For Brute Force Approach, we can use recursion by checking if the characters at the current indices are the same and if not, 
//we can either insert a character at the left or right end and recursively check for the remaining substring.
int DFS3(string s,int i,int j){
    if(i>1){
        return 0;
    }
    if(s[i]==s[j]){
        return DFS3(s,i+1,j-1);
    }
    return 1+min(DFS3(s,i+1,j),DFS3(s,i,j-1));
}
int minInsertionsBruteForce(string s){
    return DFS3(s,0,s.size()-1);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS4(string s,int i,int j,vector<vector<int>>& dp){
    if(i>1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];    
    }
    if(s[i]==s[j]){
        dp[i][j]=DFS4(s,i+1,j-1,dp);
    }
    else{
        dp[i][j]=1+min(DFS4(s,i+1,j,dp),DFS4(s,i,j-1,dp));
    }
    return dp[i][j];
}
int minInsertionsBetter(string s){
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
    return DFS4(s,0,s.size()-1,dp);
} // TC=O(N*N) SC=O(N*N)+O(N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the minimum insertions needed to make the substring s[i...j] a palindrome.
int minInsertionsOptimal(string s){
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    for(int i=s.size()-1;i>=0;i--){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][s.size()-1];
} // TC=O(N*N) SC=O(N*N)
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table, but we will need to keep track of the indices to reconstruct the minimum insertions needed.
int minInsertionsSpaceOptimized(string s){
    vector<int> prev(s.size(),0),curr(s.size(),0);
    for(int i=s.size()-1;i>=0;i--){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                curr[j]=prev[j-1];
            }
            else{
                curr[j]=1+min(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[s.size()-1];
} // TC=O(N*N) SC=O(N)
//Problem 4: Minimum Insertions/Deletions to Convert String A to String B
//For Brute Force Approach, we can use recursion by checking if the characters at the current indices are the same and if not,
//we can either insert a character in string A or delete a character from string A and recursively check for the remaining substrings.
int DFS5(string text1,string text2,int i,int j){
    if(i==text1.size()){
        return text2.size()-j;
    }
    if(j==text2.size()){
        return text1.size()-i;
    }
    if(text1[i]==text2[j]){
        return DFS5(text1,text2,i+1,j+1);
    }
    return 1+min(DFS5(text1,text2,i+1,j),DFS5(text1,text2,i,j+1));
}
int minInsertionsDeletionsBruteForce(string text1,string text2){
    return DFS5(text1,text2,0,0);
} // TC=O(2^(M+N)) SC=O(M+N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS6(string text1,string text2,int i,int j,vector<vector<int>>& dp){
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
        dp[i][j]=DFS6(text1,text2,i+1,j+1,dp);
    }
    else{
        dp[i][j]=1+min(DFS6(text1,text2,i+1,j,dp),DFS6(text1,text2,i,j+1,dp));
    }
    return dp[i][j];
}
int minInsertionsDeletionsBetter(string text1,string text2){
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
    return DFS6(text1,text2,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][j] represents the minimum insertions/deletions needed to convert the substring text1[0...i-1] to text2[0...j-1].
int minInsertionsDeletionsOptimal(string text1,string text2){
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
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
} // TC=O(M*N) SC=O(M*N)
//For Space Optimized Approach, we will optimize by using two 1D arrays to store the results of the previous and current rows of the dp table, but we will need to keep track of the indices to reconstruct the minimum insertions/deletions needed.
int minInsertionsDeletionsSpaceOptimized(string text1,string text2){
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
                curr[j]=prev[j-1];
            }
            else{
                curr[j]=1+min(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[text2.size()];
} // TC=O(M*N) SC=O(N)
int main(){
    string s1="abcjklp",s2="acjkp";
    cout<<longestCommonSubstringBruteForce(s1,s2)<<endl; 
    cout<<longestCommonSubstringOptimal(s1,s2)<<endl;
    cout<<longestCommonSubstringSpaceOptimized(s1,s2)<<endl;
    cout<<minInsertionsDeletionsBruteForce(s1,s2)<<endl;
    cout<<minInsertionsDeletionsBetter(s1,s2)<<endl;
    cout<<minInsertionsDeletionsOptimal(s1,s2)<<endl;
    cout<<minInsertionsDeletionsSpaceOptimized(s1,s2)<<endl;
    string s="bbbab";
    cout<<longestPalindromeSubsequenceBruteForce(s)<<endl;
    cout<<longestPalindromeSubsequenceBetter(s)<<endl;
    cout<<longestPalindromeSubsequenceOptimal(s)<<endl;
    cout<<longestPalindromeSubsequenceSpaceOptimized(s)<<endl;
    cout<<minInsertionsBruteForce(s)<<endl;
    cout<<minInsertionsBetter(s)<<endl;
    cout<<minInsertionsOptimal(s)<<endl;
    cout<<minInsertionsSpaceOptimized(s)<<endl; 
    return 0;
}