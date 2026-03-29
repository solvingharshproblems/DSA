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
//Problem 2: Convert binary to decimal
int binaryToDecimal(string s){
    int res=0;
    int p=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            res+=p;
        }
        p=p*2;
    }
    return res;
} // TC=O(n) SC=O(1)
int main(){
    cout<<decimalToBinary(10)<<endl;
    cout<<binaryToDecimal("1010")<<endl;
    return 0;
}