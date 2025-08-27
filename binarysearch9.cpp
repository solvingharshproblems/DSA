#include <iostream>
using namespace std;
//Problem 1: Painter's Partition or split array - largest sum 
bool CanWeAllocate(int arr[],int n,int k,int minCanvas){
    int painterCount=1;
    int canvasAllocated=0;
    for(int i=0;i<n;i++){
        if(canvasAllocated+arr[i]>minCanvas){
            painterCount++;
            canvasAllocated=arr[i];
            if(painterCount>k) return false;
        }
        else {
            canvasAllocated+=arr[i];
        }
    }
    return true;
}
void PaintersPartition(int arr[],int n,int k){
    int low=arr[n-1];
    int high=0,mid,result=-1;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    while(low<=high){
        mid=(low+high)/2;
        if(CanWeAllocate(arr,n,k,mid)){
            result=mid;
            high=mid-1;
        } 
        else {
            low=mid+1;
        }
    }
    cout<<"The minimum time to paint all boards is: "<<result<< endl;
} //TC=O(n log m)+O(n) 
//Problem 2: Minimise the maximum distance between gas stations
int CanWePlace(int arr[],int n,long double minDist){
    int count=0;
    for(int i=1;i<n;i++){
        int num=(arr[i]-arr[i-1])/minDist;
        if(num==num*minDist){
            num--;
        }
        count+=num;
    }
    return count;
}
void MinimiseMaxDistance(int n,int arr[],int k){
    sort(arr,arr+n);
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,((long double)(arr[i+1]-arr[i])));
    }
    long double diff=1e-6;
    while(high-low>diff){
        long double mid=(low+high)/2.0;
        int count=CanWePlace(arr,n,mid);
        if(count>k){
            low=mid;
        }
        else {
            high=mid;
        }
    }
    cout<<"The minimum distance between gas stations is: "<<high<<endl;
} //TC=O(n log m)+O(n)
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int k;
    /*
    cout<<"Enter the number of painters: ";
    cin>>k;
    PaintersPartition(arr,size,k);
    */
    cout<<"Enter the number of gas stations: ";
    cin>>k;
    MinimiseMaxDistance(size,arr,k);
    return 0;
}