//In Dynamic Programming, we often use memoization or tabulation to optimize recursive solutions.
//Memoization: tend to store the value of sub problems in some maps/tables so that we do not have to compute them again.
#include <iostream>
using namespace std;
//Problem 1: Fibonacci Number
//For Optimal Approach, we will use memoization to store the computed Fibonacci numbers.
int fib(int n){
    vector<int> dp(n+1,-1); // Create a dp array to store Fibonacci numbers
    if(n<=1){ 
        return n; // Base case
    }
    if(dp[n]!=-1){ 
        return dp[n]; // Return already computed Fibonacci number
    }
    dp[n]=fib(n-1)+fib(n-2); // Compute and store the Fibonacci number
    return dp[n];
} // TC=O(N) SC=O(N) 
//Tabulation: we solve the problem in a bottom-up manner by solving all related sub-problems first and using their results to build on and arrive at solutions to bigger sub-problems.
//Problem 2: Fibonacci Number using Tabulation
int fibTab(int n){
    if(n<=1){ 
        return n; // Base case
    }
    vector<int> dp(n+1,0); 
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]; // Build the dp array in a bottom-up manner
    }
    return dp[n];
} // TC=O(N) SC=O(N)
//Space Optimization: We can optimize the space used in the tabulation method by storing only the last two computed values.
//Problem 3: Fibonacci Number using Space Optimization
int fibSpaceOpt(int n){
    if(n<=1){ 
        return n; // Base case
    }
    int a=0; // F(0)
    int b=1; // F(1)
    int c;
    for(int i=2;i<=n;i++){
        c=a+b; // F(n) = F(n-1) + F(n-2)
        a=b; // Update F(n-2)
        b=c; // Update F(n-1)
    }
    return c;
} // TC=O(N) SC=O(1)
//Problem 4: Climb Stairs
//You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//For Optimal Approach, we will use memoization to store the computed number of ways to climb stairs.
//Shortcut Trick to apply on the all Dynamic Programming Problems:
//Step 1: Try to represent the problem in terms of index.
//Step 2: Try to find the relation between the current index and previous indices.
//Step 3: If the problem says, count all ways, then sum up all the ways . If the problem says, find the minimum/maximum, then take min/max accordingly.
int climbStairs(int n){
    if(n<=1){
        return 1;
    }
    int a=1; // Ways to climb 0 stairs
    int b=1; // Ways to climb 1 stair
    int c;
    for(int i=2;i<=n;i++){
        c=a+b; // Ways to climb n stairs = Ways to climb (n-1) stairs + Ways to climb (n-2) stairs
        a=b; // Update ways to climb (n-2) stairs
        b=c; // Update ways to climb (n-1) stairs
    }
    return c;
} // TC=O(N) SC=O(1) 
int main(){
    int n;
    cout<<"Enter a number to find its Fibonacci: ";
    cin>>n;
    cout<<"Fibonacci of "<<n<<" is: "<<fib(n)<<endl;
    cout<<"Fibonacci of "<<n<<" using Tabulation is: "<<fibTab(n)<<endl;
    cout<<"Fibonacci of "<<n<<" using Space Optimization is: "<<fibSpaceOpt(n)<<endl;
    int stairs;
    cout<<"Enter number of stairs to climb: ";
    cin>>stairs;
    cout<<"Number of ways to climb "<<stairs<<" stairs is: "<<climbStairs(stairs)<<endl;
    return 0;
}