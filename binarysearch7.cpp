#include <iostream>
using namespace std;
//Problem 1: Least capacity to ship packages within D days
int Shipping(int capacity,int n,int arr[]){
    int days=1,currentLoad=0;
    for(int i=0;i<n;i++){
        if(currentLoad+arr[i]<=capacity){
            currentLoad+=arr[i];
        }
        else{
            days++;
            currentLoad=arr[i];
        }
    }
    return days;
}
void LeastCapacity(int n,int arr[],int days){
    int low=0,mid,result=-1;
    int high=0;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    while(low<=high){
        mid=(low+high)/2;
        int requiredDays=Shipping(mid,n,arr);
        if(requiredDays<=days){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        } 
    }
    cout<<"Least capacity to ship packages within "<<days<<" days is: "<<result<<endl;
} //TC = O(n log m) + O(n) 
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int days;
    cout<<"Enter the number of days: ";
    cin>>days;
    LeastCapacity(size,arr,days);
    return 0;
}