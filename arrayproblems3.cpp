#include <iostream>
using namespace std;
void FindingMissingNo(int n,int arr[]){
    int sum=(n*(n+1))/2; // Sum of first n natural numbers
    int s=0;
    for(int i=0;i<n-1;i++){
        s+=arr[i]; // Sum of elements in the array
    }
    int missingNo=sum-s; // The missing number is the difference between the expected sum and the actual sum
    cout<<missingNo<<endl; // Output the missing number
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
    cout<<"The resultant is: ";
    FindingMissingNo(size, arr);
    return 0;
}