#include <iostream>
#include <unordered_set>
using namespace std;
//Problem 1: Find leaders in an array
void FindingLeaders(int n,int arr[]){
    int maxRight = arr[n - 1];
    cout<< maxRight << " "; // The last element is always a leader
    for(int i=n-2;i>=0;i--){
        if(arr[i] > maxRight){
            maxRight = arr[i];
            cout << arr[i] << " ";
        }
    }
}
//Problem 2: Find the longest consecutive subsequence in an array
void FindingSequence(int n,int arr[]){
    unordered_set<int> s;
    int longest=1;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    for(auto it : s){
        if(s.find(it-1) == s.end()){ // Check if it is the start of a sequence
            int currentNum = it;
            int currentStreak = 1;
            while(s.find(currentNum + 1) != s.end()){ // Count the length of the sequence
                currentNum++;
                currentStreak++;
            }
            longest = max(longest, currentStreak);
        }
    }
    cout<<longest << endl; // Output the length of the longest consecutive subsequence
}
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    cout << "The result is: ";
    //FindingLeaders(size, arr);
    FindingSequence(size, arr); 
    return 0;
}