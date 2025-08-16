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
//Problem 2: Merge sorted arrays without any extra space 
void MergeArrayBruteForce(long long arr1[],long long arr2[],int n,int m){
    long long arr3[n+m];
    int left=0,right=0,index=0;
    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
            arr3[index]=arr1[left];
            left++,index++;
        }
        else{
            arr3[index]=arr2[right];
            right++,index++;
        }
    }
    while(left<n){
        arr3[index++]=arr1[left++];
    }
    while(right<m){
        arr3[index++]=arr2[right++];
    }
    for(int i=0;i<n+m;i++){
        if(i<n){
            arr1[i]=arr3[i];
        }
        else{
            arr2[i-n]=arr3[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int j=0;j<m;j++){
        cout<<arr2[j]<<" ";
    }
}
void MergeArrayBetter(long long arr1[],long long arr2[],int n,int m){
    int left=n-1,right=0;
    while(left>0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int j=0;j<m;j++){
        cout<<arr2[j]<<" ";
    }
}
void SwapIfGreater(long long arr1[],long long arr2[],int n,int m){
    if(arr1[n]>arr2[m]){
        swap(arr1[m],arr2[m]);
    }
}
void MergeArrayOptimal(long long arr1[],long long arr2[],int n,int m){
    int len=n+m;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            if(left<n && right>=n){
                SwapIfGreater(arr1,arr2,left,right-n);
            }
            else if(left>=n){
                SwapIfGreater(arr2,arr2,left-n,right-n);
            }
            else{
                SwapIfGreater(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int j=0;j<m;j++){
        cout<<arr2[j]<<" ";
    }
}
int main(){
    /*
    vector<vector<int>> arr={{1,3},{2,6},{8,10},{15,18}};
    cout<<MergeIntervalBruteForce(arr)<<endl;
    cout<<MergeIntervalsOptimal(arr)<<endl;
    */ 
    int n,m;
    cout<<"Enter size of 1st array: ";
    cin>>n;
    long long arr1[n];
    cout<<"Enter the elements of 1st array: ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter size of 2nd array: ";
    cin>>m;
    long long arr2[m];
    cout<<"Enter the elements of 2nd array: ";
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    cout<<"Resultant array: "<<endl;
    MergeArrayBruteForce(arr1,arr2,n,m);
    cout<<endl;
    MergeArrayBetter(arr1,arr2,n,m);
    cout<<endl;
    MergeArrayOptimal(arr1,arr2,n,m);
    return 0;
}