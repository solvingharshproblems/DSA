#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
//Problem 1: Finding 2nd largest element of an array
void FindingElement(int n,int arr[]){
    int maxx=0;
    maxx=*max_element(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==maxx){
            arr[i]=INT_MIN;
            break;
        }
    }
    int maxx2=*max_element(arr,arr+n);
    cout<<maxx2;
}
//Problem 2: Check if an array is sorted
void CheckingArray(int n,int arr[]){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            cout<<"Array is Not sorted!"<<endl;
            sort(arr,arr+n);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//Problem 3: Removing duplicate values from an array
void RemovingDuplicates(int n,int arr[]){
    unordered_set<int>us;
    for(int i=0;i<n;i++){
        if(us.find(arr[i])==us.end()){
            cout<<arr[i]<<" ";
            us.insert(arr[i]);
        }
    }
}
int main(){
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    } /*
    cout<<"The 2nd largest element is: ";
    FindingElement(size,arr); 
    CheckingArray(size,arr); */
    RemovingDuplicates(size,arr);
    return 0;
}