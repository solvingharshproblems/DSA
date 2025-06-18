#include <iostream>
#include <algorithm>
using namespace std;
//Problem 1: Finding 2nd largest element of an array
void FindingElement(int n,int arr[]){
    int maxx=0;
    maxx=*max_element(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==maxx){
            arr[i]=INT_MIN;
            break;
        }
    }
    int maxx2=*max_element(arr,arr+n);
    cout<<maxx2;
}
int main(){
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The 2nd largest element is: ";
    FindingElement(size,arr);
    return 0;
}