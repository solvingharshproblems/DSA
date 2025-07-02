#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Set Matrix Zeroes
void SettingZeros(int n,int m,vector<vector<int>>& arr){
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0]=0; // Mark the first column
                if(j!=0){  
                    arr[0][j]=0; // Mark the first row
                }
                else{ 
                    col0=0; // If the first column is zero, set col0 to 0
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0; // Set the cell to zero if its row or column is marked
            }
        }
    }
    if(arr[0][0]==0){ // If the first cell is zero, set the first row to zero
        for(int j=0;j<m;j++){
            arr[0][j]=0;
        }
    }
    if(col0==0){ // If the first column is marked, set it to zero
        for(int i=0;i<n;i++){
            arr[i][0]=0;
        }
    }
    // Output the modified matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
}
int main(){
    int rows,columns;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>columns;
    vector<vector<int>> arr(rows, vector<int>(columns));
    cout<<"Enter the elements of the matrix:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"The result is: "<<endl;
    SettingZeros(rows, columns, arr);
    return 0;
}