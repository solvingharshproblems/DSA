#include <iostream>
#include <map>
using namespace std;
//Problem 1: Find the majority element in an array
void FindingMajorityElement(int n,int arr[]){
    // We can use a hash map to count the occurrences of each element
    //But thats not the most optimal solution
    //For optimal solution we will use Boyer-Moore Voting Algorithm
    //This algorithm works by maintaining a count of the current candidate for majority element
    //and a count of how many times it has been seen.
    //If the count reaches zero, we switch to a new candidate.
    //At the end, the candidate will be the majority element if it exists.
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