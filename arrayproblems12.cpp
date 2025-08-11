#include <iostream>
using namespace std;
//Rotate matrix by 90 degrees clockwise
//Brute force approach
void RotateMatrixBrute(int arr[][100],int n,int m){
    int table[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            table[j][n-1-i]=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=table[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
//Optimal approach
void TransposeMatrix(int arr[][100],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            if(i != j) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
}
void RotateMatrixOptimal(int arr[][100], int n, int m) {
    TransposeMatrix(arr, n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m/2;j++){
            swap(arr[i][j], arr[i][m-1-j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;
    int arr[100][100];
    cout << "Enter elements of the matrix:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << "Matrix after rotation by 90 degrees clockwise:" << endl;
    //RotateMatrixBrute(arr, n, m);
    RotateMatrixOptimal(arr, n, m);
    return 0;
}