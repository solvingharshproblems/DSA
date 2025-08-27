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
    cout<<"Enter the number of painters: ";
    cin>>k;
    PaintersPartition(arr,size,k);
    return 0;
}