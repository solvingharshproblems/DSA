#include <iostream>
using namespace std;
//Problem 1: Buy and Sell Stock - IV
//You can complete at most k transactions. However, you must sell the stock before you buy again.
//For Brute Force Approach, we can use recursion to find all possible combinations of buying and selling the stock with at most k transactions and return the maximum profit.
int DFS1(vector<int>& prices,int i,bool canBuy,int transactions,int k){
    if(i==prices.size()){
        return 0;
    }
    if(canBuy){
        if(transactions<k){
            return max(-prices[i]+DFS1(prices,i+1,false,transactions,k),DFS1(prices,i+1,true,transactions,k));
        }
        else{
            return DFS1(prices,i+1,true,transactions,k);
        }
    }
    else{
        return max(prices[i]+DFS1(prices,i+1,true,transactions+1,k),DFS1(prices,i+1,false,transactions,k));
    }
}
int maxProfitBruteForce(vector<int>& prices,int k){
    return DFS1(prices,0,true,0,k);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(vector<int>& prices,int i,bool canBuy,int transactions,int k,vector<vector<int>>& dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[i][canBuy*3+transactions]!=-1){
        return dp[i][canBuy*3+transactions];
    }
    if(canBuy){
        if(transactions<k){
            dp[i][canBuy*3+transactions]=max(-prices[i]+DFS2(prices,i+1,false,transactions,k,dp),DFS2(prices,i+1,true,transactions,k,dp));
            return dp[i][canBuy*3+transactions];
        }
        dp[i][canBuy*3+transactions]=DFS2(prices,i+1,true,transactions,k,dp);
        return dp[i][canBuy*3+transactions];
    }
    dp[i][canBuy*3+transactions]=max(prices[i]+DFS2(prices,i+1,true,transactions+1,k,dp),DFS2(prices,i+1,false,transactions,k,dp));
    return dp[i][canBuy*3+transactions];
}
int maxProfitBetter(vector<int>& prices,int k){
    vector<vector<int>> dp(prices.size(),vector<int>(3*k,-1));
    return DFS2(prices,0,true,0,k,dp);
} // TC=O(N*2*k) SC=O(N*2*k)
//For Optimal Approach, we can use tabulation to fill a dp table iteratively based on the recursive relation defined in the DFS function.
int maxProfitOptimal(vector<int>& prices,int k){
    vector<vector<int>> dp(prices.size()+1,vector<int>(3*k,0));
    for(int i=prices.size()-1;i>=0;i--){
        for(int canBuy=0;canBuy<=1;canBuy++){
            for(int transactions=0;transactions<k;transactions++){
                if(canBuy){
                    dp[i][canBuy*3+transactions]=max(-prices[i]+dp[i+1][0*3+transactions],dp[i+1][1*3+transactions]);
                }
                else{
                    dp[i][canBuy*3+transactions]=max(prices[i]+dp[i+1][1*3+(transactions+1)],dp[i+1][0*3+transactions]);
                }
            }
        }
    }
    return dp[0][1*3+0];
} // TC=O(N*2*k) SC=O(N*2*k)
int main(){
    int n=3,k=2;
    vector<int> prices={2,4,1};
    cout<<maxProfitBruteForce(prices,k)<<endl;
    cout<<maxProfitBetter(prices,k)<<endl;
    cout<<maxProfitOptimal(prices,k)<<endl;
    return 0;
}