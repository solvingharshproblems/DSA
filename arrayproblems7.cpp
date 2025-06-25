#include <iostream>
using namespace std;
//Problem 1: Find maximum subarray sum
void MaxSubArraySum(int n,int arr[]){
    //For the most optimal solution, we can use Kadane's algorithm
    int maxx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum<0){
            sum=0; // Reset sum if it becomes negative
        }
        sum+=arr[i];
        if(sum>maxx){
            maxx=sum;
        }
    }
    cout<<maxx;
}
//Problem 2: Best time to buy and sell stock
void BestTime2BuyNSellStock(int n,int arr[]){
    int minIndex = 0;
    int maxProfit = 0;
    int buy = 0, sell = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[minIndex] > maxProfit) {
            maxProfit = arr[i] - arr[minIndex];
            buy = minIndex;
            sell = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    if(maxProfit <= 0) {
        cout<<"No profitable transaction possible."<<endl;
        return;
    }
    else{
        cout<<"Buy on day: "<<buy+1<<", Sell on day: "<<sell+1<<", Profit: "<<maxProfit<<endl;
    }
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    cout<<"The result is: ";
    //MaxSubArraySum(size, arr);
    BestTime2BuyNSellStock(size, arr);
    return 0;
}