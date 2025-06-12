#include <iostream>
#include <cmath>
using namespace std;
void extractingDigits(int n){
    while(n>0){
        int last_digit=n%10;
        cout<<last_digit<<endl;
        n=n/10;
    }
}
void countingDigits(int n){
    /*
    //method 1:
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    cout<<count<<endl;
    */
    //method 2:
    int cnt;
    if(n==0){
        cout<<"Undefined value.";
    }
    else{
        cnt=(int)(log10(n)+1);
        cout<<cnt;
    }
}
void reversingNumber(int n){
    while(n>0){
        int digit=n%10;
        if(digit==0){
            cout<<"";
        }
        else{
            cout<<digit;
        }
        n=n/10;
    }
}
void checkingPalindrome(int n){
    int original=n;
    int reversed=0;
    while(n>0){
        int digit=n%10;
        reversed=reversed*10+digit;
        n=n/10;
    }
    if(reversed==original){
        cout<<"It is a Palindrome.";
    }
    else{
        cout<<"No Palindrome.";
    }
}
void checkingPrime(int n){
    bool isPrime=true;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            isPrime=false;
            break;
        }
    }
    if(isPrime){
        cout<<"It is a prime number.";
    }else{
        cout<<"It is not a prime number.";
    }
   
}
int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;
    checkingPrime(a);
    return 0;
}