#include <iostream>
using namespace std;
//Problem 1: Aggresive Cows
//Find a configuration, such that minimum distance between 2 cows is maximized
bool CanWePlace(int arr[],int n,int cows,int minDist){
    int lastPos = arr[0];
    cows--;
    for(int i = 1;i<n;i++){
        if(arr[i]-lastPos>=minDist){
            lastPos=arr[i];
            cows--;
        }
        if(cows==0) return true;
    }
    return false;
}
void AggresiveCows(int arr[],int n,int cows){
    int low=0,mid;
    int high=arr[n-1]-arr[0];
    int result=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(CanWePlace(arr,n,cows,mid)){
            result=mid;
            low=mid+1;
        } 
        else {
            high=mid-1;
        }
    }
    cout<<"The largest minimum distance is: "<<result<< endl;
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
    int cows;
    cout<<"Enter the number of cows: ";
    cin>>cows;
    AggresiveCows(arr,size,cows);
    return 0;
}