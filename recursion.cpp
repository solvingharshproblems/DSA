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
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    printingReverseNumbers(n,n);
    return 0;
}