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
//Problem 2: Find the minimum element in a rotated sorted array
void MinimumElement(int n,int arr[]){
    int low=0,mid,high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break; // Array is not rotated, so the first element is the minimum
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1; // Move to the right side
        }
        else{
            ans=min(ans,arr[mid]);
            high=mid-1; // Move to the left side
        }
    }
    cout<<"Minimum element is: "<<ans<<endl;
}
//TC = O(log n) 
//Problem 3: Find out how many times a sorted array is rotated
// we just need to find the index of the minimum element
// and that will be the number of rotations
// This is because the array is sorted and then rotated, so the minimum element's index gives the number of rotations.
// If the array is not rotated, the minimum element will be the first element.
void CountRotations(int n,int arr[]){
    int low=0,mid,high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                ans=arr[low];
                index=low; // Found the minimum element at index low
            }
            break; // Array is not rotated, so the first element is the minimum
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ans=arr[low];
                index=low; // Found the minimum element at index low
            }
            low=mid+1; // Move to the right side
        }
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                index=mid; // Found the minimum element at index mid
            }
            high=mid-1; // Move to the left side
        }
    }
    cout<<"Number of rotations: "<<index<<endl;
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
    /*
    int key;
    cout<<"Enter key to search: ";
    cin>>key;
    FindingElement(arr,size,key);
    MinimumElement(size, arr);
    */
    CountRotations(size, arr);
    return 0;
}