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
//Problem 2: Find the longest consecutive subsequence in an array
void FindingSequence(int n,int arr[]){
    int count=0,index=0;
    for(int i=0;i<n;i++){
        if(arr[i] == arr[i+1] - 1){
            count++;
        } else {
            if(count > index){
                index = count;
            }
            count = 0;
        }
    }
    cout << index + 1; // Adding 1 to include the last element in the sequence
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
    //FindingLeaders(size, arr);
    FindingSequence(size, arr); 
    return 0;
}