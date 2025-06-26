#include <iostream>
using namespace std;
//Problem 1: Find next permutation of a given array
// TC of O(n) and SC of O(1)
void nextPermutation(int arr[], int n) {
    next_permutation(arr, arr + n);
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
    nextPermutation(arr, size);
    cout << "Next permutation is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}