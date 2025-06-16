#include <iostream>
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
    cout<<"The sorted array is: ";
    InsertionSort(size,arr);
    return 0;
}