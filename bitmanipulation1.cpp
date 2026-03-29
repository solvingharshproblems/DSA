#include <iostream>
using namespace std;
//Problem 1: Convert decimal to binary
string decimalToBinary(int n){
    string res="";
    while(n>0){
        if(n%2==1){
            res+='1';
        }
        else{
            res+='0';
        }
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
} // TC=O(log n) SC=O(1)
int main(){
    cout<<decimalToBinary(10)<<endl;
    return 0;
}