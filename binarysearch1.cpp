#include <iostream>
#include <algorithm> //For using lower_bound and upper_bound functions
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
//Problem 1: Find lower bound of an element in a sorted array
//For Brute Force approach, you can use linear search to find the first occurence of the element.
//For Optimal approach, you can use binary search.
void LowerBound(int n,int arr[],int key){
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
    if(ans==n){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Lower bound of "<<key<<" is at index: "<<ans<<endl;
    }
} //TC=O(log n)
//For simplier implementation, you can use the lower_bound function from the STL.
void LowerBoundSTL(int n,int arr[],int key){
    auto it=lower_bound(arr,arr+n,key);
    if(it==arr+n){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Lower bound of "<<key<<" is at index: "<<it-arr<<endl;
    }
} //TC=O(log n)
//Problem 2: Find upper bound of an element in a sorted array
//For Brute Force approach, you can use Linear search to find the first element greater than the given element.
//For Optimal approach, you can use binary search.
void UpperBound(int n,int arr[],int key){
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
    if(ans==n){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Upper bound of "<<key<<" is at index: "<<ans<<endl;
    }
} //TC=O(log n)
//For simplier implementation, you can use the upper_bound function from the STL.
void UpperBoundSTL(int n,int arr[],int key){
    auto it=upper_bound(arr,arr+n,key);
    if(it==arr+n){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Upper bound of "<<key<<" is at index: "<<it-arr<<endl;
    }
} //TC=O(log n)
//Problem 3: Find the search insert position of an element in a sorted array
//For every Brute Force approach in binary search problems, you can use linear search
//For Optimal approach, it is exactly same as lower bound problem.
void SearchInsertPosition(int n,int arr[],int key){
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
    cout<<"Search insert position of "<<key<<" is at index: "<<ans<<endl;
}
//TC = O(log n)
//Problem 4: Find floor and ceil of an element in a sorted array
//Floor is the largest element less than or equal to the given element.
//Ceil is the smallest element greater than or equal to the given element.
void Floor(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    int ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<=key){
            ans=arr[mid];
            low=mid+1; //We want the largest element less than or equal to key
        }
        else{
            high=mid-1; //We want the smallest element greater than or equal to key
        }
    }
    if(ans==-1){
        cout<<"Floor of "<<key<<" not found!"<<endl;
    }
    else{
        cout<<"Floor of "<<key<<" is: "<<ans<<endl;
    }
} // TC = O(log n)
void Ceil(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    int ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=key){
            ans=arr[mid];
            high=mid-1; //We want the smallest element greater than or equal to key
        }
        else{
            low=mid+1; //We want the largest element less than or equal to key
        }
    }
    if(ans==-1){
        cout<<"Ceil of "<<key<<" not found!"<<endl;
    }
    else{
        cout<<"Ceil of "<<key<<" is: "<<ans<<endl;
    }
} //TC = O(log n)
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
    /*
    BinarySearch1(size,arr,key);
    BinarySearch2(size,arr,0,key);
    LowerBound(size,arr,key);
    LowerBoundSTL(size,arr,key);
    UpperBound(size,arr,key);
    UpperBoundSTL(size,arr,key);
    SearchInsertPosition(size,arr,key);
    */
    Floor(size,arr,key);
    Ceil(size,arr,key);
    return 0;
}