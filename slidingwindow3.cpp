#include <iostream>
using namespace std;
//Problem 1: Fruit into Baskets
//You are visiting a farm that has a single row of fruit trees arranged from left to right.
//The trees are represented by an integer array fruits where fruits[i] is the type of fruit the i-th tree produces.
//You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
//1. You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
//2. Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right.
//The picked fruits must fit in one of your baskets.
//Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
//Given the integer array fruits, return the maximum number of fruits you can pick.
//We can convert this question to find the longest subarray with at most 2 distinct characters
//For Brute Force Approach, we can generate all subarrays and check if they have at most 2 distinct characters. If they do, we can update the maxLength
void FruitIntoBasketsBruteForce(int n,int arr[]){
    int maxLength=0;
    for(int i=0;i<n;i++){
        int hash[100001]={0};
        int distinctCount=0;
        for(int j=i;j<n;j++){
            if(hash[arr[j]]==0){
                distinctCount++;
            }
            hash[arr[j]]++;
            if(distinctCount>2){
                break;
            }
            int length=j-i+1;
            maxLength=max(maxLength,length);
        }
    }
    cout<<"Length of longest subarray with at most 2 distinct characters is: "<<maxLength<<endl;
} // TC=O(n^2) SC=O(n)
//For Better Approach, we can use sliding window technique
//We can maintain a window with at most 2 distinct characters and update the maxLength
void FruitIntoBasketsBetter(int n,int arr[]){
    int maxLength=0;
    int left=0;
    int right=0;
    int hash[100001]={0};
    int distinctCount=0;
    while(right<n){
        if(hash[arr[right]]==0){
            distinctCount++;
        }
        hash[arr[right]]++;
        while(distinctCount>2){
            hash[arr[left]]--;
            if(hash[arr[left]]==0){
                distinctCount--;
            }
            left++;
        }
        int length=right-left+1;
        maxLength=max(maxLength,length);
        right++;
    }
    cout<<"Length of longest subarray with at most 2 distinct characters is: "<<maxLength<<endl;
} // TC=O(2n) SC=O(n)
//For Optimal Approach, we will try to remove the inner while loop
void FruitIntoBasketsOptimal(int n,int arr[]){
    int maxLength=0;
    int left=0;
    int right=0;
    int hash[100001]={0};
    int distinctCount=0;
    while(right<n){
        if(hash[arr[right]]==0){
            distinctCount++;
        }
        hash[arr[right]]++;
        if(distinctCount>2){
            hash[arr[left]]--;
            if(hash[arr[left]]==0){
                distinctCount--;
            }
            left++;
        }
        int length=right-left+1;
        maxLength=max(maxLength,length);
        right++;
    }
    cout<<"Length of longest subarray with at most 2 distinct characters is: "<<maxLength<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    FruitIntoBasketsBruteForce(n,arr);
    FruitIntoBasketsBetter(n,arr);
    FruitIntoBasketsOptimal(n,arr);
    return 0;
}