#include <iostream>
using namespace std;
//Problem 1: Sort an array just containing 0s, 1s, and 2s
void Sorting(int n,int arr[]){
    //We gonna use the Dutch National Flag algorithm to sort the array, it states
    int low=0,mid=0,high=n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array (0s, 1s, and 2s only): ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    Sorting(size, arr);
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}