#include <iostream>
#include <map>
using namespace std;
//Problem 1: Find the majority element in an array
void FindingMajorityElement(int n,int arr[]){
    //For optimal solution we will use Boyer-Moore Voting Algorithm
    int count=0,element;
    for(int i=0;i<n;i++){
        if(count == 0){
            element = arr[i];
            count = 1;
        } else if(arr[i] == element){
            count++;
        } else {
            count--;
        }
    }
    //and if the array might not contain a majority element
    int count1=0;
    for(int i=0;i<n;i++){
        if(arr[i] == element){
            count1++;
        }
    }
    if(count1 <= n/2){
        cout << "No majority element found." << endl;
        return;
    }
    cout<<element;
}   
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout<<"The result is: "; 
    FindingMajorityElement(size, arr);
    return 0;
}