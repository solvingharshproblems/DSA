#include <iostream>
using namespace std;
//Problem 1: Buy and Sell Stock - II
//You can buy and sell the stock multiple times. However, you must sell the stock before you buy again.
//For Brute Force Approach, we can use recursion to find all possible combinations of buying and selling the stock and return the maximum profit.
int DFS1(vector<int>& prices,int i,bool canBuy){
    if(i==prices.size()){
        return 0;
    }
    if(canBuy){
        return max(-prices[i]+DFS1(prices,i+1,false),DFS1(prices,i+1,true));
    }
    return max(prices[i]+DFS1(prices,i+1,true),DFS1(prices,i+1,false));
}
int maxProfit2BruteForce(vector<int>& prices){
    return DFS1(prices,0,true);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(vector<int>& prices,int i,bool canBuy,vector<vector<int>>& dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[i][canBuy]!=-1){
        return dp[i][canBuy];
    }
    if(canBuy){
        dp[i][canBuy]=max(-prices[i]+DFS2(prices,i+1,false,dp),DFS2(prices,i+1,true,dp));
        return dp[i][canBuy];
    }
    dp[i][canBuy]=max(prices[i]+DFS2(prices,i+1,true,dp),DFS2(prices,i+1,false,dp));
    return dp[i][canBuy];
}
int maxProfit2Better(vector<int>& prices){
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return DFS2(prices,0,true,dp);
} // TC=O(N) SC=O(N)+O(N)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][canBuy] represents the maximum profit that can be achieved from day i to the end of the prices array, given whether we can buy or not.
int maxProfit2Optimal(vector<int>& prices){
    vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
    for(int i=prices.size()-1;i>=0;i--){
        for(int canBuy=0;canBuy<=1;canBuy++){
            if(canBuy){
                dp[i][canBuy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }
            else{
                dp[i][canBuy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
} // TC=O(N) SC=O(N)
//For Space Optimized Approach, we will return profit directly without using a dp table, as we only need the results from the next day to calculate the current day's profit.
int maxProfit(vector<int>& prices) {
    int profit=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            profit+=prices[i]-prices[i-1];
        }
    }
    return profit;
} // TC=O(N) SC=O(1)
//Problem 2: Buy and Sell Stock - III
//You can complete at most two transactions. However, you must sell the stock before you buy again.
//For Brute Force Approach, we can use recursion to find all possible combinations of buying and selling the stock with at most two transactions and return the maximum profit.
int DFS3(vector<int>& prices,int i,bool canBuy,int transactions){
    if(i==prices.size()){
        return 0;
    }
    if(canBuy){
        if(transactions<2){
            return max(-prices[i]+DFS3(prices,i+1,false,transactions),DFS3(prices,i+1,true,transactions));
        }
        return DFS3(prices,i+1,true,transactions);
    }
    return max(prices[i]+DFS3(prices,i+1,true,transactions+1),DFS3(prices,i+1,false,transactions));
}
int maxProfit3BruteForce(vector<int>& prices){
    return DFS3(prices,0,true,0);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS4(vector<int>& prices,int i,bool canBuy,int transactions,vector<vector<int>>& dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[i][canBuy*3+transactions]!=-1){
        return dp[i][canBuy*3+transactions];
    }
    if(canBuy){
        if(transactions<2){
            dp[i][canBuy*3+transactions]=max(-prices[i]+DFS4(prices,i+1,false,transactions,dp),DFS4(prices,i+1,true,transactions,dp));
            return dp[i][canBuy*3+transactions];
        }
        dp[i][canBuy*3+transactions]=DFS4(prices,i+1,true,transactions,dp);
        return dp[i][canBuy*3+transactions];
    }
    dp[i][canBuy*3+transactions]=max(prices[i]+DFS4(prices,i+1,true,transactions+1,dp),DFS4(prices,i+1,false,transactions,dp));
    return dp[i][canBuy*3+transactions];
}
int maxProfit3Better(vector<int>& prices){
    vector<vector<int>> dp(prices.size(),vector<int>(6,-1));
    return DFS4(prices,0,true,0,dp);
} // TC=O(N) SC=O(N)+O(N*6)
//For Optimal Approach, we will use tabulation to fill a 2D array where dp[i][canBuy*3+transactions] represents the maximum profit that can be achieved from day i to the end of the prices array, given whether we can buy or not and the number of transactions completed.
int maxProfit3Optimal(vector<int>& prices){
    vector<vector<int>> dp(prices.size()+1,vector<int>(6,0));
    for(int i=prices.size()-1;i>=0;i--){
        for(int canBuy=0;canBuy<=1;canBuy++){   
            for(int transactions=0;transactions<3;transactions++){
                if(canBuy){
                    dp[i][canBuy*3+transactions]=max(-prices[i]+dp[i+1][0*3+transactions],dp[i+1][1*3+transactions]);
                }
                else{
                    if(transactions<2){
                            dp[i][canBuy*3+transactions]=max(prices[i]+dp[i+1][1*3+(transactions+1)],dp[i+1][0*3+transactions]);
                    }
                    else{
                        dp[i][canBuy*3+transactions]=dp[i+1][0*3+transactions];
                    }
                }
            }
        }
    }
    return dp[0][1*3+0];
} // TC=O(N) SC=O(N*6)
int main(){
    int n=5;
    vector<int> prices={7,1,5,3,6,4};
    cout<<"Maximum profit that can be achieved from the given stock prices: "<<maxProfit2BruteForce(prices)<<endl;
    cout<<"Maximum profit that can be achieved from the given stock prices: "<<maxProfit2Better(prices)<<endl;
    cout<<"Maximum profit that can be achieved from the given stock prices: "<<maxProfit2Optimal(prices)<<endl;
    cout<<"Maximum profit that can be achieved from the given stock prices: "<<maxProfit(prices)<<endl;
    cout<<"Maximum profit that can be achieved from the given stock prices with at most two transactions: "<<maxProfit3BruteForce(prices)<<endl;
    cout<<"Maximum profit that can be achieved from the given stock prices with at most two transactions: "<<maxProfit3Better(prices)<<endl;
    cout<<"Maximum profit that can be achieved from the given stock prices with at most two transactions: "<<maxProfit3Optimal(prices)<<endl;
    return 0;
}