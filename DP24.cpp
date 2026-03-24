#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
//Problem 1: Evaluate Boolean Expression to True
//Given a boolean expression consisting of symbols 0 (false), 1 (true), & (AND), | (OR), and ^ (XOR), and a desired boolean result value result, 
//implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result.
//For Brute Force Approach, we can use recursion to find all possible combinations of parent hesizing the expression and return the count of those combinations which evaluate to the desired result.
int DFS1(string expression,int i,int j,int result){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(result==1){
            return expression[i]=='T';
        }
        else{
            return expression[i]=='F';
        }
    }
    ll res=0;
    for(int k=i+1;k<=j-1;k+=2){
        ll LT=DFS1(expression,i,k-1,1);
        ll LF=DFS1(expression,i,k-1,0);
        ll RT=DFS1(expression,k+1,j,1);
        ll RF=DFS1(expression,k+1,j,0);
        if(expression[k]=='&'){
            if(result==1){
                res=(res+(LT*RT)%mod)%mod;
            }
            else{
                res=(res+(LF*RT)%mod+(LT*RF)%mod+(LF*RF)%mod)%mod;
            }
        }
        else if(expression[k]=='|'){
            if(result==1){
                res=(res+(LF*RT)%mod+(LT*RF)%mod+(LT*RT)%mod)%mod;
            }
            else{
                res=(res+(LF*RF)%mod)%mod;
            }
        }
        else if(expression[k]=='^'){
            if(result==1){
                res=(res+(LF*RT)%mod+(LT*RF)%mod)%mod;
            }
            else{
                res=(res+(LF*RF)%mod+(LT*RT)%mod)%mod;
            }
        }
    }
    return res;   
}
int parseBoolExprBruteForce(string expression){
    int n=expression.size();
    return DFS1(expression,0,n-1,1);
} //TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(string expression,int i,int j,int result,vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(result==1){
            return expression[i]=='T';
        }
        else{
            return expression[i]=='F';
        }
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll res=0;
    for(int k=i+1;k<j;k+=2){
        ll LT=DFS2(expression,i,k-1,1,dp);
        ll LF=DFS2(expression,i,k-1,0,dp);
        ll RT=DFS2(expression,k+1,j,1,dp);
        ll RF=DFS2(expression,k+1,j,0,dp);
        if(expression[k]=='&'){
            if(result==1){
                res=(res+(LT*RT)%mod)%mod;
            }
            else{
                res=(res+(LF*RT)%mod+(LT*RF)%mod+(LF*RF)%mod)%mod;
               
            }
        }
        else if(expression[k]=='|'){
            if(result==1){
                res=(res+(LF*RT)%mod+(LT*RF)%mod+(LT*RT)%mod)%mod;
            }
            else{
                res=(res+(LF*RF)%mod)%mod;
            }
        }
        else if(expression[k]=='^'){
            if(result==1){
                res=(res+(LT*RF)%mod+(LF*RT)%mod)%mod;
            }
            else{
                res=(res+(LT*RT)%mod+(LF*RF)%mod)%mod;
            }
        }
    }
    dp[i][j]=res;
    return res;
}
int parseBoolExprBetter(string expression){
    int n=expression.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return DFS2(expression,0,n-1,1,dp);
} //TC=O(N^3) SC=O(N^2)+O(N)
//For Optimal Approach, we will use tabulation to fill a dp table iteratively based on the recursive relation defined in the DFS function.
int parseBoolExprOptimal(string expression){
    int n=expression.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=expression[i]=='T';
            }
            else{
                ll res=0;
                for(int k=i+1;k<j;k+=2){
                    ll LT=dp[i][k-1];
                    ll LF=1-dp[i][k-1];
                    ll RT=dp[k+1][j];
                    ll RF=1-dp[k+1][j];
                    if(expression[k]=='&'){
                        res=(res+(LT*RT)%mod)%mod;
                    }
                    else if(expression[k]=='|'){
                        res=(res+(LT*RT)%mod+(LT*RF)%mod+(LF*RT)%mod)%mod;
                    }
                    else if(expression[k]=='^'){
                        res=(res+(LT*RF)%mod+(LF*RT)%mod)%mod;
                    }
                }
                dp[i][j]=res;
            }
        }
    }
    return dp[0][n-1];
} //TC=O(N^3) SC=O(N^2)
int main(){
    string expression="&(|(f))";
    if(parseBoolExprBruteForce(expression)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    if(parseBoolExprBetter(expression)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    if(parseBoolExprOptimal(expression)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}