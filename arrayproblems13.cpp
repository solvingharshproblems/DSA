#include <iostream>
using namespace std;
//Spiral order traversal of a matrix
void SpiralOrderTraversal(int arr[][100], int n, int m){
    int top=0,right=m-1,bottom=n-1,left=0;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<< " ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<< " ";
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i]<< " ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<< " ";
            }
            left++;
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    int arr[100][100];
    cout<<"Enter elements of the matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Spiral order traversal of the matrix:" <<endl;
    SpiralOrderTraversal(arr,n,m);
    return 0;
}