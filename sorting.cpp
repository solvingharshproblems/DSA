#include <iostream>
#include <vector>
using namespace std;
void SelectionSort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int MinIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[MinIndex]){
                MinIndex=j;
            }
        }
        swap(arr[i],arr[MinIndex]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
} //Bubble Sort better than Selection Sort
void Bubblesort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
} //Insertion Sort better than both
void InsertionSort(int n,int arr[]){
    int key=0;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void Merge(int arr[],int low,int mid,int high){
    vector <int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }
    for(int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}
void MergeSort(int arr[],int low,int high){ //Divide and Merge
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}
//Yall crazy IMMA SHOW YOU THE SIMPLE SHIT
void SortingArray(int n,int arr[]){
    sort(arr, arr + n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    MergeSort(arr,0,size-1);
    cout<<"The sorted array is: ";
    //InsertionSort(size,arr);
    for(int i=0;i<size;i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;
}