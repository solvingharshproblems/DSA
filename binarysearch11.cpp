#include <iostream>
using namespace std;
//Problem 1: Find the row with maximum 1's in a 2D sorted array
//You can use upper bound(0) or lower bound(1) or first occurence(1) any of the already solved method
//and implement them in each row as we move forward
int LowerBound(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    int ans=n;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=key){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
void RowWithMax1s(int n,int m,int arr[][100]){
    int count_max=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int count_1s=m-LowerBound(m,arr[i],1);
        if(count_1s>count_max){
            count_max=count_1s;
            index=i;
        }
    }
    cout<<"Row with maximum 1's is: "<<index<<endl;
} //TC=O(N*log(M))
int main(){
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    int cols;
    cout<<"Enter the number of columns: ";
    cin>>cols;
    cout<<"Enter the elements of the array:"<<endl;
    int arr[100][100];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
    RowWithMax1s(rows,cols,arr);
    return 0;
}