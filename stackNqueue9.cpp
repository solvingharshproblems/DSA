#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Online Stock Span Problem
//We need to return the possible integer value of maximum consicutive days for which the stock price is less than or equal to current price
//For Optimal Approach part 1 we can declare a class with dynamic array and for each new price we can iterate backwards to count the number of days
class StockSpanner1{
    stack<pair<int,int>> s; //pair of price and span
    public:
        StockSpanner1(){
        }
        int next(int price){
            int count=1;
            while(!s.empty() && s.top().first<=price){
                count+=s.top().second;
                s.pop();
            }
            s.push({price,count});
            return count;
        }
}; //TC=Θ(1) or O(n) || SC=O(n)
//For Optimal Approach part 2 we can use stack to store the price and the span of that price using the logic of previous greater element
class StockSpanner2{
    stack<pair<int,int>> st; //pair of price and span
    int index=-1;
    public:
        StockSpanner2(){
            index=-1;
        }
        int next(int price){
            index++;
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            int ans=index-(st.empty()?-1:st.top().second);
            st.push({price,index});
            return ans;
        }
}; //TC=Θ(1) or O(n) || SC=O(n)
//Problem 2: Sliding Window Maximum
//Given an array and an integer k, we need to find the maximum for each and every contiguous subarray of size k
//For Brute Force Approach we can use two loops to iterate through the array and find the maximum for each subarray of size k
void SlidingWindowMaximumBruteForce(int n,int arr[],int k){
    for(int i=0;i<=n-k;i++){
        int max=arr[i];
        for(int j=i;j<i+k;j++){
            if(arr[j]>max){
                max=arr[j];
            }
        }
        cout<<max<<" ";
    }
    cout<<endl;
} //TC=O(n*k) || SC=O(1)
//For Optimal Approach we will use stack to store the next greater element for each element in the array and then use that to find the maximum for each subarray of size k
void SlidingWindowMaximumOptimal1(int n,int arr[],int k){
    int nge[n]; //next greater element
    stack<int> s; //stack to store the indices of the elements
    s.push(n-1);
    nge[n-1]=n; //no next greater element for the last element
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        nge[i]=s.empty()?n:s.top();
        s.push(i);
    }
    for(int i=0;i<=n-k;i++){
        int j=i;
        while(nge[j]<i+k){
            j=nge[j];
        }
        cout<<arr[j]<<" ";
    }
    cout<<endl;
} //TC=O(n) || SC=O(n)
//For Optimal Approach part 2 we can use deque to store the indices of the elements in the current window and maintain the maximum at the front of the deque
void SlidingWindowMaximumOptimal2(int n,int arr[],int k){
    deque<int> dq; //deque to store the indices of the elements
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }
    cout<<endl;
} //TC=O(n) || SC=O(k)
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    /*
    StockSpanner2* obj=new StockSpanner2();
    for(int i=0;i<size;i++){
        int price;
        cout<<"Enter the price of stock on day "<<i+1<<": ";
        cin>>price;
        cout<<"The stock span for day "<<i+1<<" is: "<<obj->next(price)<<endl;
    }
    delete obj;
    */
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the size of subarray: ";
    cin>>k;
    cout<<"The maximum element in each subarray is: ";
    SlidingWindowMaximumBruteForce(size,arr,k);
    cout<<"The maximum element in each subarray is: ";
    SlidingWindowMaximumOptimal1(size,arr,k);
    cout<<"The maximum element in each subarray is: ";
    SlidingWindowMaximumOptimal2(size,arr,k);
    return 0;
}