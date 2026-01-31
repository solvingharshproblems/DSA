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
int main(){
    int n;
    cout<<"Enter a number to find its Fibonacci: ";
    cin>>n;
    cout<<"Fibonacci of "<<n<<" is: "<<fib(n)<<endl;
    return 0;
}