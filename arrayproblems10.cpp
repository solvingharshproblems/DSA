#include <iostream>
using namespace std;
//Problem 1: Find leaders in an array
void FindingLeaders(int n,int arr[]){
    int maxRight = arr[n - 1];
    cout<< maxRight << " "; // The last element is always a leader
    for(int i=n-2;i>=0;i--){
        if(arr[i] > maxRight){
            maxRight = arr[i];
            cout << arr[i] << " ";
        }
    }
}
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    cout << "The result is: ";
    FindingLeaders(size, arr);
    return 0;
}