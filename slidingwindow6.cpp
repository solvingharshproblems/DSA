#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;
//Problem 1: Subarrays with K Different Integers
//For Brute Force Approach, we can use a nested loop to find all the subarrays and check if they have k different integers
void CountSubarraysBruteForce(vector<int>& arr,int k){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        unordered_map<int,int> mp;
        for(int j=i;j<n;j++){
            mp[arr[j]]++;
            if(mp.size()==k){
                count++;
            }
            else if(mp.size()>k){
                break;
            }
        }
    }
    cout<<"Count of subarrays with k different integers is: "<<count<<endl;
} // TC=O(n^2) SC=O(n)
//For Optimal Approach, we will try to find subarrays less than or equal to k different integers and subtract it from subarrays less than or equal to k-1 different integers
int CountSubarraysOptimal(vector<int>& arr,int k){
    int n=arr.size();
    int left=0;
    int right=0;
    unordered_map<int,int> mp;
    long long count=0;
    while(right<n){
        mp[arr[right]]++;
        while(mp.size()>k && left<=right){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}
void PrintSubarraysOptimal(vector<int>& arr,int k){
    cout<<"Count of subarrays with k different integers is: "<<CountSubarraysOptimal(arr,k)-CountSubarraysOptimal(arr,k-1)<<endl;
} // TC=O(n) SC=O(n)
//Problem 2: Minimum Window Substring
//Given two strings s and t, return the minimum window in s which will contain all the characters in t
//For Brute Force Approach, we can use a nested loop to find all the substrings and check if they contain all the characters in t
void MinWindowSubstringBruteForce(string s,string t){
    int n=s.size();
    int m=t.size();
    int minLength=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
       int hash[256]={0};
       for(int j=0;j<m;j++) hash[t[j]]++;
       int count=m;
       for(int j=i;j<n;j++){
           if(hash[s[j]]>0){
               count--;
           }
           hash[s[j]]--;
           if(count==0){
               if(j-i+1<minLength){
                   minLength=j-i+1;
                   index=i;
               }
               break;
           }
       }
    }
    if(index==-1){
        cout<<"No such window exists"<<endl;
    }
    else{
        cout<<"Minimum window substring is: "<<s.substr(index,minLength)<<endl;
    }
} // TC=O(n^2) SC=O(n)
//For Optimal Approach, we will use sliding window technique and hashmap to store the count of characters in t
int MinWindowSubstringOptimal(string s,string t){
    int n=s.size();
    int m=t.size();
    int hash[256]={0};
    int l=0,r=0,count=0;
    int minLen=INT_MAX;
    int sIndex=-1;
    for(int i=0;i<m;i++) hash[t[i]]++;
    count=m;
    while(r<n){
        if(hash[s[r]]>0){
            count--;
        }
        hash[s[r]]--;
        while(count==0){
            if(r-l+1<minLen){
                minLen=r-l+1;
                sIndex=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0){
                count++;
            }
            l++;
        }
        r++;
    }
    if(sIndex==-1){
        return -1;
    }
    else{
        cout<<"Minimum window substring is: "<<s.substr(sIndex,minLen)<<endl;
        return minLen;
    }
} // TC=O(2n) SC=O(n)
int main(){
    /*
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    CountSubarraysBruteForce(arr,k);
    PrintSubarraysOptimal(arr,k);
    */
    string s,t;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string t: ";
    cin>>t;
    MinWindowSubstringBruteForce(s,t);
    MinWindowSubstringOptimal(s,t);
    return 0;
}