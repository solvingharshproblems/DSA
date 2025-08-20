#include <iostream>
using namespace std;
//Problem 1: Find the first and last occurence of an element in a sorted array
//For the optimal approach, we can use lower bound and upper bound functions from earleir problems
//and implement them in firstnlastoccurence function
int LowerBound(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    int ans=n;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=key){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
} 
int UpperBound(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    int ans=n;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>key){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
} 
void FirstNLastOccurence(int n,int arr[],int key){
    int lb=LowerBound(n,arr,key);
    if(lb==n || arr[lb]!=key){
        return;
    }
    cout<<"First occurence of "<<key<<" is at index: "<<lb<<endl;
    cout<<"Last occurence of "<<key<<" is at index: "<<UpperBound(n,arr,key)-1<<endl;
} //TC = O(2*log n) 
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of an array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key to search: ";
    cin>>key;
    FirstNLastOccurence(size,arr,key);
    return 0;
}