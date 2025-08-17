#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Find the repeating and missing numbers in an array
void FindingNumbersInArrayBruteForce(int arr[],long long n){
    int repeating=-1,missing=-1;
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                count++;
            }
        }
        if(count==2) repeating=i;
        else if(count==0) missing=i;
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }
    cout<<"Repeating number: "<<repeating<<"\t Missing number: "<<missing<<endl;
} //TC = (n^2)
//For better solution we'll use a hash array
void FindingNumbersInArrayBetter(int arr[],long long n){
    vector<int> v(n+1,0);
    int repeating=-1,missing=-1;
    for(int i=0;i<n;i++){
        v[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            missing=i;
        }
        else if(v[i]==2){
            repeating=i;
        }
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }
    cout<<"Repeating number: "<<repeating<<"\t Missing number: "<<missing<<endl;
}
//For 1st optimal solution we'll use mathematical logics 
void FindingNumbersInArrayOptimal1(int arr[],long long n){
    long long x,y,sum1=0,sum2=0;
    long long total=(n*(n+1))/2;
    long long square=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        sum1+=arr[i];
        sum2+=(long long)arr[i]*(long long)arr[i];
    }
    long long val1=sum1-total;
    long long val2=sum2-square;
    val2=val2/val1;
    x=(val1+val2)/2;
    y=x-val1;
    cout<<"Repeating number: "<<(int)x<<"\t Missing number: "<<(int)y<<endl;
}
//For 2nd optimal solution we'll use XOR concept
void FindingNumbersInArrayOptimal2(int arr[],long long n){
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    int number=xr & ~(xr-1);
    int zero=0,one=0;
    for(int i=0;i<n;i++){
        if((arr[i] & number)!=0){
            //One club
            one=one^arr[i];
        }
        else{
            //Zero club
            zero=zero^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((i & number)!=0){
            one =one^i;
        }
        else{
            zero=zero^i;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==zero) count++;
    }
    if(count==2){
        cout<<"Repeating number: "<<zero<<"\t Missing number: "<<one<<endl;
    }
    else{
        cout<<"Repeating number: "<<one<<"\t Missing number: "<<zero;
    }
}
int main(){
    long long size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    FindingNumbersInArrayBruteForce(arr,size);
    FindingNumbersInArrayBetter(arr,size);
    FindingNumbersInArrayOptimal1(arr,size);
    FindingNumbersInArrayOptimal2(arr,size);
    return 0;
}