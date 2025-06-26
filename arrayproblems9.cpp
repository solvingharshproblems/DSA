#include <iostream>
using namespace std;
//Problem 1: Find next permutation of a given array
// TC of O(n) and SC of O(1)
void nextPermutation(int arr[], int n) {
    next_permutation(arr, arr + n);
}
// But if stl is not allowed, we can implement it manually
void nextPermutationManual(int arr[], int n) {
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break; 
        }
    }
    if(index==1){
        reverse(arr, arr + n);
        return;
    }
    for(int i=n-1;i>index;i--){
        if(arr[i]>arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    } 
    reverse(arr + index + 1, arr + n);
}
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    //nextPermutation(arr, size);
    nextPermutationManual(arr, size);
    cout << "Next permutation is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}