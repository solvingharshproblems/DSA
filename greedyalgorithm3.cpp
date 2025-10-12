#include <iostream>
using namespace std;
//Problem 1: Shortest Job First (SJF) Scheduling
//Scheduling policy that selects the waiting process with the smallest execution time to execute next
//For Optimal Approach, we will sort the array and calculate the average waiting time
void SJFScheduling(vector<int> arr){
    int n=arr.size();
    int avg=0,sum=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        avg+=sum;
        sum+=arr[i];
    }
    cout<<"Average waiting time: "<<avg/n<<endl;
} // TC=O(nlogn) SC=O(1) Here, we tamper the input array by sorting it which is not a good practice
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SJFScheduling(arr);
    return 0;
}