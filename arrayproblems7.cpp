#include <iostream>
using namespace std;
//Problem 1: Find maximum subarray sum
void maxSubArraySum(int n, int arr[]) {
    //For the most optimal solution, we can use Kadane's algorithm
    // In this algorithm, we iterate through the array and keep track of the maximum sum of subarrays ending at each index.
    // We also keep track of the overall maximum sum found so far.
    int maxx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum < 0) {
            sum = 0; // Reset sum if it becomes negative
        }
        sum += arr[i];
        if(sum>maxx) {
            maxx = sum;
        }
    }
    cout<<maxx;
}
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout<<"The result is: ";
    maxSubArraySum(size, arr);
    return 0;
}