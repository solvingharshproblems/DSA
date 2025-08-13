#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//Problem 1: Find majority element n/3 times
void MajorityElementBruteForce(int n,int arr[]){
    vector<int> ls;
    int count=0;
    for(int i=0;i<n-1;i++){
        if(ls.size()==0 || ls[0]!=arr[i]){
            count=0;
            for(int j=0;j<n-1;j++){
                if(arr[j]==arr[i]){
                    count++;
                }
            }
            if(count > n/3){
                ls.push_back(arr[i]);
                cout<<arr[i]<<" ";
                
            }
        }
        if(ls.size() == 2) {
            break; // We can only have at most two majority elements
        }
    }
}
//For better solution, we can use a hash map
void MajorityElementBetter(int n,int arr[]){
    unordered_map<int,int> ump;
    bool found = false;
    vector<int> result;
    for(int i=0;i<n;i++){
        ump[arr[i]]++;
    }
    for(const auto &it:ump){
        if(it.second > n/3){
            found = true;
            result.push_back(it.first);
            
        }
    }
    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    if(!found) {
        cout<<"No majority element found"<<endl;
    } else {
        cout<<endl;
    }
    if(result.size()==2){
        return;
    }
}
//For optimal solution, we'll use a modified version of Boyer-Moore Voting Algorithm
void MajorityElementOptimal(int n,int arr[]){
    int count1=0,element1=INT_MIN,count2=0,element2=INT_MIN;
    for(int i=0;i<n;i++){
        if(count1==0 && arr[i]!=element2){
            count1=1;
            element1=arr[i];
        }
        else if(count2==0 && arr[i]!=element1){
            count2=1;
            element2=arr[i];
        }
        else if(arr[i]==element1){
            count1++;
        }
        else if(arr[i]==element2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    vector<int> result;
    count1=0; count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element1) count1++;
        if(arr[i]==element2) count2++;
    }
    int minCount=(n/3)+1;
    if(count1 >= minCount) result.push_back(element1);
    if(count2 >= minCount) result.push_back(element2);
    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
//Problem 2: Count subarrays with XOR as k
void XORSubarrayBruteForce(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorSum=0;
            for(int l=i;l<=j;l++){
                xorSum ^= arr[l];
            }
            if(xorSum == k){
                count++;
            }
        }
    }
    cout << "Total subarrays with XOR equal to " << k << ": " << count << endl;
}
//For better solution, we can simply remove the inner loop and use a prefix XOR array
void XORSubarrayBetter(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        int xorSum=0;
        for(int j=i;j<n;j++){
            xorSum ^= arr[j];
            if(xorSum == k){
                count++;
            }
        }
    }
    cout << "Total subarrays with XOR equal to " << k << ": " << count << endl;
}
//For optimal solution, we can use a hash map to store the prefix XOR sums
void XORSubarrayOptimal(int arr[],int n,int k){
    int count=0;
    int prefixXor=0;
    unordered_map<int, int> prefixMap;
    prefixMap[0] = 1; // To handle the case when prefix XOR equals k
    for(int i=0;i<n;i++){
        prefixXor^=arr[i];
        int remove=prefixXor^k; // XOR with k to find the required prefix
        count+=prefixMap[remove]; // Count how many times this prefix XOR has occurred
        prefixMap[prefixXor]++; // Store the current prefix XOR in the map
    }
    cout << "Total subarrays with XOR equal to " << k << ": " << count << endl;
} //Note: Printing the subarrays might increase complexity, so it's not included in the optimal solution
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //MajorityElementBruteForce(size,arr);
    //MajorityElementBetter(size,arr);
    //MajorityElementOptimal(size,arr);
    int variable;
    cout<<"Enter the variable for XOR subarray: ";
    cin>>variable;
    XORSubarrayBruteForce(arr, size, variable);
    XORSubarrayBetter(arr, size, variable);
    XORSubarrayOptimal(arr, size, variable);
    return 0;
}