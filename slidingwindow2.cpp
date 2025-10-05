#include <iostream>
using namespace std;
//Problem 1: Longest Substring Without Repeating Characters
//Given a string s, find the length of the longest substring without repeating characters.
//For Brute Force Approach, we can generate all substrings and check if they have all unique characters
//If they do, we can update the maxLength
void LongestSubstringBruteForce(string s){
    int n=s.size();
    int maxLength=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string substr=s.substr(i,j-i+1);
            bool allUnique=true;
            for(int k=0;k<substr.size();k++){
                for(int l=k+1;l<substr.size();l++){
                    if(substr[k]==substr[l]){
                        allUnique=false;
                        break;
                    }
                }
                if(!allUnique){
                    break;
                }
            }
            if(allUnique){
                maxLength=max(maxLength,(int)substr.size());
            }
        }
    }
    cout<<"Length of longest substring without repeating characters is: "<<maxLength;
} // TC=O(n^3) SC=O(1)
//For Better Approach, we can use a hash array to store the last index of each character
void LongestSubstringBetter(string s){
    int n=s.size();
    int maxLength=0;
    for(int i=0;i<n;i++){
        int hash[256]={0};
        for(int j=i;j<n;j++){
            if(hash[s[j]]==1){
                break;
            }
            int length=j-i+1;
            hash[s[j]]++;
            maxLength=max(maxLength,length);
        }
    }
    cout<<"Length of longest substring without repeating characters is: "<<maxLength;
} // TC=O(n^2) SC=O(n)
//For Optimal Approach, we will use sliding window technique
void LongestSubstringOptimal(string s){
    int n=s.size();
    int maxLength=0;
    int left=0;
    int right=0;
    int hash[256]={0};
    while(right<n){
        int length=right-left+1;
        if(hash[s[right]]==0){
            hash[s[right]]++;
            maxLength=max(maxLength,length);
            right++;
        }
        else{
            hash[s[left]]--;
            left++;
        }
    }
    cout<<"Length of longest substring without repeating characters is: "<<maxLength;
} // TC=O(n) SC=O(n)
//Problem 2: Maximum Consecutive Ones III
//Given a binary array nums and an integer k, return the length of maximum number of consecutive 1s in the array if you can flip at most k 0s.
//We can convert this question to find the longest subarray with at most k 0s
//For Brute Force Approach, we can generate all subarrays and check if they have at most k 0s. If they do, we can update the maxLength
void MaxConsecutiveOnesBruteForce(vector<int> arr,int k){
    int n=arr.size();
    int maxLength=0;
    for(int i=0;i<n;i++){
        int zeroCount=0;
        for(int j=i;j<n;j++){
            if(arr[j]==0){
                zeroCount++;
            }
            if(zeroCount>k){
                break;
            }
            int length=j-i+1;
            maxLength=max(maxLength,length);
        }
    }
    cout<<"Length of longest subarray with at most "<<k<<" 0s is: "<<maxLength;
} // TC=O(n^2) SC=O(1)
//For Better Approach, we can use sliding window technique
//We can maintain a window with at most k 0s and update the maxLength
void MaxConsecutiveOnesBetter(vector<int> arr,int k){
    int n=arr.size();
    int maxLength=0;
    int left=0;
    int right=0;
    int zeroCount=0;
    while(right<n){
        if(arr[right]==0){
            zeroCount++;
        }
        while(zeroCount>k){
            if(arr[left]==0){
                zeroCount--;
            }
            left++;
        }
        int length=right-left+1;
        maxLength=max(maxLength,length);
        right++;
    }
    cout<<"Length of longest subarray with at most "<<k<<" 0s is: "<<maxLength;
} // TC=O(2n) SC=O(1)
//For Optimal Approach, we will use sliding window technique and we will try to remove the inner while loop
void MaxConsecutiveOnesOptimal(vector<int> arr,int k){
    int n=arr.size();
    int maxLength=0;
    int left=0;
    int right=0;
    int zeroCount=0;
    while(right<n){
        if(arr[right]==0){
            zeroCount++;
        }
        if(zeroCount>k){
            if(arr[left]==0){
                zeroCount--;
            }
            left++;
        }
        int length=right-left+1;
        maxLength=max(maxLength,length);
        right++;
    }
    cout<<"Length of longest subarray with at most "<<k<<" 0s is: "<<maxLength;
} // TC=O(n) SC=O(1)
int main(){
    /*
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    LongestSubstringBruteForce(s);
    cout<<endl;
    LongestSubstringBetter(s);
    cout<<endl;
    LongestSubstringOptimal(s);
    */
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the number of 0s that can be flipped: ";
    cin>>k;
    MaxConsecutiveOnesBruteForce(arr,k);
    cout<<endl;
    MaxConsecutiveOnesBetter(arr,k);
    cout<<endl;
    MaxConsecutiveOnesOptimal(arr,k);
    return 0;
}