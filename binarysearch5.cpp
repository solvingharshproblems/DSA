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
//Problem 2: Koko Eating Bananas
int HourlyRate(int arr[],int n,int k){
    int totalHours=0;
    for(int i=0;i<n;i++){
        totalHours+=ceil((double)arr[i]/k);
    }
    return totalHours;
}
void KokoEatingBananas(int n,int arr[],int hours){
    int low=1,mid,k=INT_MAX;
    int high=*max_element(arr,arr+n);
    while(low<=high){
        mid=(low+high)/2;
        int totalHours=HourlyRate(arr,n,mid);
        if(totalHours<=hours){
            k=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"The minimum eating speed is: "<<k;
} //TC = O(n log max(arr)) 
int main(){
    /*
    int n,m;
    cout<<"Enter the value : ";
    cin>>m;
    cout<<"Enter the value of nth root to find: ";
    cin>>n;
    FindingNthRoot(n,m);
    */
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int hours;
    cout<<"Enter the hours for Koko to eat bananas: ";
    cin>>hours;
    KokoEatingBananas(size,arr,hours);
    return 0;
}