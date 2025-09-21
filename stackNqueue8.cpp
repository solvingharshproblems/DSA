#include <iostream>
#include <stack>
#include <list>
using namespace std;
//Problem 1: Nearest Smaller Element on the left side
//For Brute Force Approach we will check for each element the nearest smaller element on the left side by traversing the array from the current element to the start of the array.
void SmallerElementBruteForce(int arr[],int n){
    int nse[n];
    for(int i=0;i<n;i++){
        nse[i]=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                nse[i]=arr[j];
                break;
            }
            if(j==0){
                cout<<"-1 ";
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<nse[i]<<" ";
    }
} //TC=O(n^2) SC=O(n)
//For Optimal Approach we will use a stack to keep track of the nearest smaller elements.
list<int> SmallerElementOptimal(int arr[],int n){
    stack<int> s;
    list<int> nse;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            nse.push_back(-1);
        }
        else{
            nse.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return nse;
} //TC=O(2n) SC=O(2n)
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Nearest Smaller Element on the left side is: ";
    SmallerElementBruteForce(arr,n);
    cout<<endl;
    cout<<"Nearest Smaller Element on the left side is: ";
    list<int> result=SmallerElementOptimal(arr,n);
    for(auto it=result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}