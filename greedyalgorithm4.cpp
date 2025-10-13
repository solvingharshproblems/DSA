#include <iostream>
using namespace std;
//Problem 1: Non Overlapping Intervals
//Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping
//For Optimal Approach, we will sort the intervals by their end times and select the intervals which start after the end of the last selected interval
//Note: This is the same as the N meetings in one room problem, just that here we have to return the number of intervals to be removed
bool CompareInterval(pair<int,int> value1, pair<int,int> value2){
    return value1.second<value2.second;
}
void NonOverlappingIntervals(vector<pair<int,int>> arr){
    int n=arr.size();   
    sort(arr.begin(),arr.end(),CompareInterval);
    int count=1;
    int limit=arr[0].second;
    for(int i=1;i<n;i++){
        if(arr[i].first>limit){
            count++;
            limit=arr[i].second;
        }
    }
    cout<<"Minimum number of intervals to be removed: "<<n-count<<endl;
} // TC=O(nlogn+n) SC=O(1)
int main(){
    int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    vector<pair<int,int>> arr(n);
    cout<<"Enter the start and end times of the intervals: ";
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    NonOverlappingIntervals(arr);
    return 0;
}