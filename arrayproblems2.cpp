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
//Problem 3: Linear Search in an array
void LinearSearch(int n,int arr[],int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Element found at the index: "<<i<<endl;
            return;
        }
    }
}
//Problem 4: Finding intersection of two arrays
void Intersection(int n1,int arr1[],int n2,int arr2[]){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
                break; // To avoid printing duplicates from arr2
            }
        }
    }
}
int main(){
    int size1;
    cout<<"Enter the size of 1st array: ";
    cin>>size1;
    int arr1[size1];
    cout<<"Enter the elements of 1st array: ";
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    int size2;
    cout<<"Enter the size of 2nd array: ";
    cin>>size2;
    int arr2[size2];
    cout<<"Enter the elements of 2nd array: ";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
     /*
    int d;
    cout<<"Enter the number of positions to rotate: ";
    cin>>d;
    LeftRotate(size, arr,d); 
    MovingZeros(size, arr); 
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    LinearSearch(size, arr,key); */
    cout<<"Resultant array: ";
    Intersection(size1,arr1,size2,arr2);
    /*
    for(int i=0;i<size1;i++){
        cout<<arr[i]<<" ";
    } */
    return 0;
}