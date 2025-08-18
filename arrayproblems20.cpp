#include <iostream>
using namespace std;
//Problem 1: Find no. of reverse pairs
void FindingReversePairsBruteForce(long long n,int arr[]){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j]){
                count++;
            }
        }
    }
    cout<<"No. of pairs are: "<<count<<endl;
}
//For optimal solution we'll use merge sort logic but also add a function for counting pairs
//this function will count the pairs while other functions merges and sorts the array
int CountPairs(int arr[],int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int left=low;left<=mid;left++){
        while(right<=high && arr[left]>2*arr[right]){
            right++;
        }
        cnt+=(right-(mid+1));
    }
    return cnt;
}
int Merge(int arr[],int low,int mid,int high){
    int cnt=0;
    vector <int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }
    for(int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
    return cnt;
}
int MergeSort(int arr[],int low,int high){ //Divide and Merge
    int cnt=0;
    if(low>=high){
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=MergeSort(arr,low,mid);
    cnt+=MergeSort(arr,mid+1,high);
    cnt+=CountPairs(arr,low,mid,high);
    Merge(arr,low,mid,high);
    return cnt;
}
void FindingReversePairsOptimal(int n,int arr[]){
    cout<<"No. of pairs are: "<<MergeSort(arr,0,n-1)<<endl;
} //TC = O(n logn + n logn) SC = O(n + n)
//Problem 2: Find the maximum product subarray
void SubarrayProductBruteForce(int n,int arr[]){
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product=1;
            for(int k=i;k<j;k++){
                product*=arr[k];
            }
            maxx=max(product,maxx);
        }
    }
    cout<<maxx<<endl;
}
void SubarrayProductBetter(int n,int arr[]){
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
        int product=1;
        for(int j=i;j<n;j++){
            product*=arr[j];
            maxx=max(product,maxx);
        }
    }
    cout<<maxx<<endl;
}
//There are 2 optimal approaches of this code 1. Observations 2. Modified version of Kadane's algorithm
//1. Observations & 2-pointer approach from starting and end 
void SubarrayProductOptimal1(int n,int arr[]){
    int maxx=INT_MIN;
    int prefix=1,suffix=1;
    for(int i=0;i<n-1;i++){
        if(prefix==0){
            prefix=1;
        }
        if(suffix==0){
            suffix=1;
        }
        prefix=prefix*arr[i];
        suffix=suffix*arr[n-i-1];
        maxx=max(maxx,max(prefix,suffix));
    }
    cout<<maxx<<endl;
}
//2. Modified version of Kadane's algorithm
void SubarrayProductOptimal2(int n,int arr[]){
    int maxx=arr[0];
    int minn=arr[0];
    int result=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<0){
            swap(maxx,minn);
        }
        maxx=max(arr[i],maxx*arr[i]);
        minn=min(arr[i],minn*arr[i]);
        result=max(result,maxx);
    }
    cout<<result;
}
//Note: Never show this approach to interviewers as this is not intuitive at all
int main(){
    long long size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    /*
    FindingReversePairsBruteForce(size,arr);
    FindingReversePairsOptimal(size,arr);
    */
    SubarrayProductBruteForce(size,arr);
    SubarrayProductBetter(size,arr);
    SubarrayProductOptimal1(size,arr);
    SubarrayProductOptimal2(size,arr);
    return 0;
}