#include <iostream>
using namespace std;
//Problem 1: Left rotate the array by d position
void Reverse(int arr[],int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void LeftRotate(int n,int arr[],int d){
    d=d%n; // To handle cases where d >= n
    Reverse(arr,0,d-1);
    Reverse(arr,d,n-1);
    Reverse(arr,0,n-1);
    // The above three reversals will effectively rotate the array left by d positions
    // First reversal reverses the first d elements
    // Second reversal reverses the remaining n-d elements
    // Third reversal reverses the entire array to get the final rotated array
}
//Problem 2: Move all zeros to the end of the array
void MovingZeros(int n,int arr[]){
    int position=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i], arr[position]);
            position++;
        }
    }
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    } /*
    int d;
    cout<<"Enter the number of positions to rotate: ";
    cin>>d;
    LeftRotate(size, arr,d); */
    MovingZeros(size, arr);
    cout<<"Resultant array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}