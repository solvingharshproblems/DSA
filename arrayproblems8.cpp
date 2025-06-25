#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Rearranging array elements by sign
void RearrangeArray(int n,int arr[]){
    vector<int>v(n);
    int posCount = 0, negCount = 1;
    for(int i=0;i<n;i++){
        if(arr[i] < 0) {
            v[negCount] = arr[i];
            negCount += 2;
        } else {
            v[posCount] = arr[i];
            posCount += 2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
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
    cout<<"The result is: ";
    RearrangeArray(size, arr);
    return 0;
}