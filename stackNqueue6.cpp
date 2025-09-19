#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Asteroid Collision
//We need to find the state of the asteroids after all collisions.
//For Optimal Approach we will use a stack to keep track of the asteroids that are still moving.
void asteroidCollisionOptimal(int arr[], int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            s.push(arr[i]);
        }
        else{
            while(!s.empty() && s.top()>0){
                if(s.top()<abs(arr[i])){
                    s.pop();
                }
                else if(s.top()==abs(arr[i])){
                    s.pop();
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<"State of asteroids after all collisions: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
} //TC=O(2n) SC=O(n)
//Problem 2: Largest Rectangle in Histogram
//We need to find the largest area of the rectangle that can be formed in the histogram.
//For Brute Force Approach we can use the logic of finding the next smaller element to the left and right of each bar.
void largestRectangleInHistogramBruteForce(int arr[],int n){
    stack<int> s;
    int leftSmall[n],rightSmall[n];
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            leftSmall[i]=-1;
        }
        else{
            leftSmall[i]=s.top();
        }
        s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            rightSmall[i]=n;
        }
        else{
            rightSmall[i]=s.top();
        }
        s.push(i);
    }
    int maxArea=0;
    for(int i=0;i<n;i++){
        int area=arr[i]*(rightSmall[i]-leftSmall[i]-1);
        maxArea=max(maxArea,area);
    }   
    cout<<"Largest area of the rectangle in the histogram: "<<maxArea;
} //TC=O(4n) SC=O(3n)
//For Optimal Approach we can multiply the height of each bar with the width of the rectangle that can be formed with that bar as the smallest bar.
void largestRectangleInHistogramOptimal(int arr[],int n){
    stack<int> s;
    int maxArea=0;
    for(int i=0;i<=n;i++){
        while(!s.empty() && (i==n || arr[s.top()]>=arr[i])){
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
    cout<<"Largest area of the rectangle in the histogram: "<<maxArea;
} //TC=O(2n) SC=O(n)
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //asteroidCollisionOptimal(arr, n);
    largestRectangleInHistogramBruteForce(arr, n);
    cout<<endl;
    largestRectangleInHistogramOptimal(arr, n);
    return 0;
}