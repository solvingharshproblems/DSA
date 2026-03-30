#include <iostream>
using namespace std;
//Problem 1: Minimum bit flips to convert a number
//For Optimal Approach, we will use the XOR operator to find the bits that are different between the two numbers. 
//Then, we will count the number of set bits in the result, which will give us the minimum number of bit flips required.
int minBitFlips(int a,int b){
    int xorResult=a^b; 
    int count=0;
    while(xorResult){
        count+=xorResult&1; 
        xorResult>>=1; 
    }
    return count; 
} // TC=O(log(max(a,b))) SC=O(1)
int main(){
    int a=29;
    int b=15;
    cout<<"Minimum bit flips required to convert "<<a<<" to "<<b<<" is: "<<minBitFlips(a,b)<<endl;
    return 0;
}