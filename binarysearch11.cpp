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
//Problem 2: Binary search in 2D sorted matrix
void BinarySearch(int n,int m,int arr[][100],int key){
    int low=0,high=n*m-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(arr[row][col]==key){
            cout<<"Element found at index: ("<<row<<","<<col<<")"<<endl;
            return;
        }
        else if(arr[row][col]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"Element not found"<<endl;
} //TC=O(log(N*M))
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
    /*
    RowWithMax1s(rows,cols,arr);
    */
    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    BinarySearch(rows,cols,arr,key);
    return 0;
}