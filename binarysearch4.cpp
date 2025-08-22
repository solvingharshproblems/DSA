#include <iostream>
using namespace std;
//Problem 1: Find the single element in sorted array where every other element appears twice
void FindingSingleElement(int n,int arr[]){
    if(n==1){
        cout<<arr[0];
        return;
    }
    if(arr[0]!=arr[1]){
        cout<<arr[0];
        return;
    }
    if(arr[n-1]!=arr[n-2]){
        cout<<arr[n-1];
        return;
    }
    int low=1,mid,high=n-2;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            cout<<"The single element is: "<<arr[mid];
            return;
        }
        if((mid%2==0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1])){
        low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
} //TC = O(log n)
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    FindingSingleElement(size,arr);
    return 0;
}