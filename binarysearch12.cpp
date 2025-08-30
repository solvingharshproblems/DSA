#include <iostream>
using namespace std;
//Problem 1: Find peak element in a 2D array i.e a element should be greater than its
// left counter part,right counter part, top counter part, bottom counter part and 2 adjacent cells are not same
//you can return index of any of the peak element 
int FindPeakUtil(int n,int m,int arr[][100],int col){
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i][col]>maxValue){
            maxValue=arr[i][col];
            index=i;
        }
    }
    return index;
}
void FindPeak(int n, int m, int arr[][100]){
    int low=0,mid,high=m-1;
    while(low<=high){
        mid=(low+high)/2;
        int row=FindPeakUtil(n,m,arr,mid);
        int left=mid-1>=0?arr[row][left]:-1;
        int right=mid+1<m?arr[row][right]:-1;
        if(arr[row][mid]>left && arr[row][mid]>right){
            cout<<"Peak element found at index: ("<<row<<","<<mid<<") with value: "<<arr[row][mid]<<endl;
            return;
        }
        if(left>arr[row][mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout << "No peak element found" << endl;
} //TC=O(N*log(M))
//Problem 2: Find median in a row wise sorted 2D array
int BlackBox(int n,int m,int arr[][100],int x){
    int count=0;
    for(int i=0;i<n;i++){
        count+=upper_bound(arr[i],arr[i]+m,x)-arr[i];
    }
    return count;
}
void FindMedian(int arr[][100],int n,int m) {
    int low=0,mid,high=n*m-1;
    int MedianPosition=(n*m+1)/2;
    while(low<=high){
        mid=(low+high)/2;
        if(BlackBox(n,m,arr,mid)<MedianPosition){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"Median is: "<<low<<endl;
} //TC=O(N*log(M))
int main(){
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;
    int arr[100][100];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    //FindPeak(n,m,arr);
    FindMedian(arr,n,m);
    return 0;
}