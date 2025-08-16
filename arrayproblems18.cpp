#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Problem 1: Find the minimum overlapping subintervals 
int MergeIntervalBruteForce(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!result.empty() && end<=result.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        result.push_back({start,end});
    }
    return result.size();
}
//TC = O(n^2+nlogn)
int MergeIntervalsOptimal(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
        if(result.empty() || arr[i][0]>result.back()[1]){
            result.push_back(arr[i]);
        }
        else{
            result.back()[1]=max(result.back()[1],arr[i][1]);
        }
    }
    return result.size();
}
//TC = O(nlogn+n)
int main(){
    vector<vector<int>> arr={{1,3},{2,6},{8,10},{15,18}};
    cout<<MergeIntervalBruteForce(arr)<<endl;
    cout<<MergeIntervalsOptimal(arr)<<endl;
    return 0;
}