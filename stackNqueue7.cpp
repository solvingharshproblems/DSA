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
//Problem 2: Remove K Digits
//We need to remove k digits from the number such that the new number is the smallest possible
//For Optimal Approach we will keep smaller digits at the top of the stack and remove larger digits from the top of the stack until we have removed k digits.
string removeKdigits(string num,int k){
    stack<char> s;
    for(int i=0;i<num.length();i++){
        while(!s.empty() && k>0 && s.top()-'0'>num[i]-'0'){
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    while(k>0 && !s.empty()){
        s.pop();
        k--;
    }
    string res="";
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    while(res.length()>1 && res.back()=='0'){
        res.pop_back();
    }
    reverse(res.begin(),res.end());
    if(res.length()==0){
        return "0";
    }
    return res;
} //TC=O(4n) SC=O(2n)
int main(){
    /*
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
    */
    string num;
    int k;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"The smallest number after removing k digits is: "<<removeKdigits(num,k);
    return 0;
}
