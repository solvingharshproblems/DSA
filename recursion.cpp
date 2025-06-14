#include <iostream>
#include <string.h>
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
int main(){
    int n,summ=0;
    cout<<"Enter a number: ";
    cin>>n;
    Sum(1,n,summ);
    cout<<summ;
    return 0;
}