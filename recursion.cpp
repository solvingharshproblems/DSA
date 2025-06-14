#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int mycount=0;//global variable
void Count(){
    if(mycount==4){
        return;
    }
    else{
        cout<<mycount<<endl;
        mycount++;
        Count();
    }
}
void Names(int i,int n){
    if(i>n){
        return;
    }
    else{
        cout<<"Harsh."<<endl;
        Names(i+1,n);
    }
}
void printingNumbers(int i,int n){
    if(i>n){
        return;
    }
    else{
        cout<<i<<endl;
        printingNumbers(i+1,n);
    }
}
void printingReverseNumbers(int i,int n){
    if((i<0)){
        return;
    }
    else{
        cout<<i<<endl;
        printingReverseNumbers(i-1,n);
    }
}
void BackTracking(int i,int n){
    if(i<1){
        return;
    }
    BackTracking(i-1,n);
    cout<<i;
}
void ReverseBackTracking(int i,int n){
    if(i<1){
        return;
    }
    cout<<i;
    ReverseBackTracking(i-1,n);
}
void Sum(int i,int n,int &summ){ //Parameterized Recursion
    if(i>n){
        return ;
    }
    else{
        summ+=i;
        Sum(i+1,n,summ);
    }
}
int Summ(int i,int n){ //Functional Recursion
    if(i>n){
        return 0;
    }
    else{
        return i+Summ(i+1,n);
    }
}
void ArrayReverse(int arr[],int a,int b){
    if(a>=b) return;
    swap(arr[a],arr[b]);
    ArrayReverse(arr,a+1,b-1);
}
void CheckingPalindrome(string n){
    string original=n;
    reverse(n.begin(),n.end());
    if(n==original){
        cout<<"It is a palindrome.";
    }
    else{
        cout<<"It is not a palindrome.";
    }
}/*
void Fibonacci(int a,int b,int n){
    if(n==0){
        return;
    }else{
        int next=a+b;
        cout<<next<<" ";
        Fibonacci(b,next,n-1);
    }
} */
//OR Position in Fibonacci Series
int FibonacciPosition(int n){
    if(n<=1){
        return n;
    }
    int last=FibonacciPosition(n-1);
    int slast=FibonacciPosition(n-2);
    return last+slast;
}
int main(){
    /*
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ArrayReverse(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } 
    string n;
    cout<<"Enter a string: ";
    getline(cin,n);
    CheckingPalindrome(n); */
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    //Fibonacci(0,1,n);
    int result=FibonacciPosition(n);
    cout<<"The value at "<<n<<" in Fibonacci series is: "<<result<<" ";
    return 0;
} 