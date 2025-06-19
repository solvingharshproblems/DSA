#include <iostream>
using namespace std;
//Problem 1: Left rotate the array by d position
void LeftRotate(int n,int arr[]){
    int d;
    d=d%n;
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"Enter the number of positions to rotate: ";
    cin>>d;
    for(int i=0;i<d;i++){
        LeftRotate(size, arr);
    }
    cout<<"Resultant array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}