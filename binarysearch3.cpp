#include <iostream>
using namespace std;
//Problem 1: It is same as previous problem, but here duplicates are allowed.
//and just tell does the element exist or not in the array
void FindingElement(int arr[],int n,int key){
    int low=0,mid,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            cout<<"Element found! "<<endl;
            return;
        }
        if(arr[low]==arr[mid]){
            low++,high--;
            continue; // This handles duplicates by skipping them
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=key && key<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=key && key<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
} //TC = O(log n) in average case, O(n/2) in worst case due to duplicates
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key to search: ";
    cin>>key;
    FindingElement(arr,size,key);
    return 0;
}