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
//Problem 2: Insert Interval
//Return the resulting array of intervals after inserting the new interval where the array of intervals is non-overlapping 
//Note: The intervals are given in sorted order according to their start times
//For Optimal Approach, if there is any overlap, we will select minimum start time and maximum end time from the overlapping intervals
//Else we will simply insert the new interval at the correct position
bool CompareInterval2(pair<int,int> value1,pair<int,int> value2){
    return value1.first<value2.first;
}
void InsertInterval(vector<pair<int,int>> arr,pair<int,int> newInterval){
    int n=arr.size();
    vector<pair<int,int>> ans;
    int i=0;
    //Adding all the intervals which end before the new interval starts
    while(i<n && arr[i].second<newInterval.first){
        ans.push_back(arr[i]);
        i++;
    }
    //Merging all the overlapping intervals
    while(i<n && arr[i].first<=newInterval.second){
        newInterval.first=min(newInterval.first,arr[i].first);
        newInterval.second=max(newInterval.second,arr[i].second);
        i++;
    }
    ans.push_back(newInterval);
    //Adding all the intervals which start after the new interval ends
    while(i<n){
        ans.push_back(arr[i]);
        i++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<"["<<ans[i].first<<","<<ans[i].second<<"] ";
    }
} // TC=O(n) SC=O(n) for storing the answer
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
    pair<int,int> newInterval;
    cout<<"Enter the start and end times of the new interval: ";
    cin>>newInterval.first>>newInterval.second;
    InsertInterval(arr,newInterval);
    cout<<endl;
    return 0;
}