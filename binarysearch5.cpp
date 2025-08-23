#include <iostream>
#include <cmath>
using namespace std;
//Problem 1: Find nth root of an integer m
void FindingNthRoot(int n,int m){
    int low=1,mid,high=m,ans=-1;
    if(m==0 || m==1){
        cout<<"The nth root is: "<<m;
        return;
    }
    if(n==0){
        cout<<"The nth root is: "<<1;
        return;
    }
    while(low<=high){
        mid=(low+high)/2;
        long long power=pow(mid,n);
        if(power==m){
            cout<<"The nth root is: "<<mid;
            return;
        }
        else if(power<m){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"The approximate value of nth root is: "<<ans;
} //TC = O(log m)
int main(){
    int n,m;
    cout<<"Enter the value : ";
    cin>>m;
    cout<<"Enter the value of nth root to find: ";
    cin>>n;
    FindingNthRoot(n,m);
    return 0;
}