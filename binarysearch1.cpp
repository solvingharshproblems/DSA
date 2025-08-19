#include <iostream>
using namespace std;
//Binary Searching in array using for loop
void BinarySearch1(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            cout<<"Element found at index: "<<mid<<endl;
            return;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
} //TC=O(log n)
//Binary Searching in array using recursion
void BinarySearch2(int high,int arr[],int low,int key){
    if(low>high){
        cout<<"Element not found!"<<endl;
        return;
    }
    int mid=(low+high)/2;
    if(arr[mid]==key){
        cout<<"Element found at index: "<<mid<<endl;
        return;
    }
    else if(arr[mid]<key){
        BinarySearch2(high,arr,mid+1,key);
    }
    else{
        BinarySearch2(mid-1,arr,low,key);
    }
} //TC=O(log n)
int main(){
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of sorted array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key to search: ";
    cin>>key;
    BinarySearch1(size,arr,key);
    BinarySearch2(size,arr,0,key);
    return 0;
}