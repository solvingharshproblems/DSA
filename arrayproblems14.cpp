#include <iostream>
#include <unordered_map>
using namespace std;
//Find number of subarrays with sum equal to k
void SubarraySumKBruteForce(int arr[], int n, int k) {
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int l=i;l<=j;l++){
                sum+=arr[l];
            }
            if(sum==k){
                count++;
                for(int l=i;l<=j;l++){
                    cout<<arr[l]<<" ";
                }
                cout << endl;
            }
        }
    }
}
void SubarraySumKBetter(int arr[],int n,int k){
    //remove most inner nested loop for optimization
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                count++;
                for(int l=i;l<=j;l++){
                    cout<<arr[l]<<" ";
                }
                cout << endl;
            }
        }
    }
}
void SubarraySumKOptimal(int arr[],int n,int k){
    //use a hash map to store prefix sums
    int count=0;    
    int prefixSum=0;
    unordered_map<int, int> prefixMap;
    prefixMap[0] = 1; // To handle the case when prefix sum equals k
    for(int i=0;i<n;i++){
        prefixSum += arr[i];
        int remove= prefixSum - k;
        count += prefixMap[remove]; // Count how many times this prefix sum has occurred
        prefixMap[prefixSum]++; // Store the current prefix sum in the map
    }
    cout << "Total subarrays with sum equal to " << k << ": " << count << endl;
} //Note: Printing the subarrays might increase complexity, so it's not included in the optimal solution
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    //SubarraySumKBruteForce(arr, size, k);
    //SubarraySumKBetter(arr, size, k);
    SubarraySumKOptimal(arr, size, k);
    return 0;
}