#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Trapping Rain Water
//We need to find the amount of water that can be trapped between the bars of different heights.
//that means we need to find the maximum height of the bars to the left and right of each bar and then find the minimum of these two heights.
//For Brute Force Approach we can use a prefixMax and suffixMax array to store the maximum height of the bars to the left and right of each bar.
void trappingRainWaterBruteForce(int arr[], int n){
    int prefixMax[n], suffixMax[n];
    prefixMax[0]=arr[0];
    for(int i=1;i<n;i++){
        prefixMax[i]=max(prefixMax[i-1], arr[i]);
    }
    suffixMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1], arr[i]);
    }
    int water=0;
    for(int i=0;i<n;i++){
        water+=min(prefixMax[i], suffixMax[i])-arr[i];
    }
    cout<<water;
} //TC=O(3n) SC=O(2n)
//For Better Approach we can reduce the space complexity to O(n) by storing only the suffixMax array and using a variable to store the prefixMax value.
void trappingRainWaterBetter(int arr[], int n){
    int suffixMax[n];
    suffixMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1], arr[i]);
    }
    int water=0;
    int prefixMax=arr[0];
    for(int i=1;i<n-1;i++){
        prefixMax=max(prefixMax, arr[i]);
        water+=min(prefixMax, suffixMax[i])-arr[i];
    }
    cout<<water;
} //TC=O(2n) SC=O(n)
//For Optimal Approach we can use two pointers to traverse the array from both ends and keep track of the maximum height of the bars to the left and right of each bar.
void trappingRainWaterOptimal(int arr[], int n){
    int left=0, right=n-1; 
    int leftMax=0, rightMax=0;
    int water=0;
    while(left<=right){
        if(arr[left]<=arr[right]){
            if(arr[left]>=leftMax){
                leftMax=arr[left];
            }
            else{
                water+=leftMax-arr[left];
            }
            left++;
        }
        else{
            if(arr[right]>=rightMax){
                rightMax=arr[right];
            }
            else{
                water+=rightMax-arr[right];
            }
            right--;
        }
    }
    cout<<water;
} //TC=O(n) SC=O(1)
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Trapped water : ";
    trappingRainWaterBruteForce(arr,n);
    cout<<endl;
    cout<<"Trapped water : ";
    trappingRainWaterBetter(arr,n);
    cout<<endl;
    cout<<"Trapped water : ";
    trappingRainWaterOptimal(arr,n);
    cout<<endl;
    return 0;
}