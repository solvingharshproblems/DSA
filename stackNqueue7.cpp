#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//Problem 1: Maximal Rectangle in a Binary Matrix
//We need to find the largest rectangle containing only 1's in a 2D binary matrix
//For Optimal Approach we can use the logic of largest rectangle in histogram for each row of the matrix.
int largestRectangleInHistogramOptimal(vector<int>& arr){
    stack<int> s;
    int n = arr.size();
    int maxArea=0;
    for(int i=0;i<=n;i++){
        while(!s.empty() && (i==n || arr[s.top()]>= (i<n ? arr[i] : 0))){
            int height=arr[s.top()];
            s.pop();
            int width;
            if(s.empty()){
                width=i; 
            }
            else{
                width=i-s.top()-1;
            }
            maxArea=max(maxArea,height*width);
        }
        s.push(i);
    }
    return maxArea;
}
int MaximalRectangleOptimal(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int maxArea=0;
    vector<vector<int>> prefixSum(n, vector<int>(m,0));
    
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=matrix[i][j];
            if(matrix[i][j]==0){
                sum=0;
            }
            prefixSum[i][j]=sum;
        }
    }

    for(int i=0;i<n;i++){
        maxArea=max(maxArea,largestRectangleInHistogramOptimal(prefixSum[i]));
    }
    return maxArea;
} //TC=O(n*m)+O(n*2m) SC=O(n*m)
int main(){
    int rows,cols;
    cout<<"Enter the rows of the matrix: ";
    cin>>rows;
    cout<<"Enter the columns of the matrix: ";
    cin>>cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"The maximal rectangle in the binary matrix is: "<<MaximalRectangleOptimal(matrix);
    return 0;
}
