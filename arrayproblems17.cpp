#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
//Problem 1: 3Sum: Find and print all unique triplets in the array that add up to zero.
void ThreeSumBruteForce(int n,int arr[]){
    set<vector<int>> s;
    bool found = false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end()); // Sort to ensure uniqueness
                    s.insert(triplet); // Insert into set to avoid duplicates
                    found = true;
                }
            }
        }
    }
    vector<vector<int>> result(s.begin(), s.end());
    for(const auto& triplet : result){
        cout << "Triplet found: ";
        for(int num : triplet){
            cout << num << " ";
        }
        cout << endl;
    }
    if(!found)
        cout<<"No such triplet found"<<endl;
    //TC = O(n^3*log N), SC = O(n) for storing unique triplets
}
//For better solution, we can use a hash map to store the indices of the elements.
void ThreeSumBetter(int n,int arr[]){
    set<vector<int>> s;
    unordered_map<int, int> ump;
    bool found=false;
    for(int i=0;i<n;i++){
        ump[arr[i]]=i; // Store the index of each element
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int complement=-(arr[i]+arr[j]); // Find the complement of the current pair
            if(ump.find(complement)!=ump.end() && ump[complement]!=i && ump[complement]!=j){
                vector<int> triplet={arr[i],arr[j],complement};
                sort(triplet.begin(),triplet.end()); // Sort to ensure uniqueness
                s.insert(triplet); // Insert into set to avoid duplicates
                found=true;
            }
        }
    }
    vector<vector<int>> result(s.begin(),s.end());
    for(const auto& triplet:result){
        cout<<"Triplet found: ";
        for(int num:triplet){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    if(!found)
        cout<<"No such triplet found"<<endl;
    //TC = O(n^2*log N), SC = O(n) for storing unique triplets
}
//For optimal solution, rather than using a set to store unique triplets,
//we can define a two-pointer approach after sorting the array.
void ThreeSumOptimal(int n,int arr[]){
    vector<vector<int>> result;
    sort(arr,arr+n); // Sort the array first
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue; // Skip duplicates
        int j=i+1,k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> triplet={arr[i],arr[j],arr[k]};
                result.push_back(triplet);
                j++;
                k--;
                while(arr[j]==arr[j-1] && j<k) j++; // Skip duplicates
                while(arr[k]==arr[k+1] && j<k) k--; // Skip duplicates
            }
        }
    }
    if(result.empty()){
        cout<<"No triplet found"<<endl;
    }
    else{
        for(auto &triplet:result){
            cout<<"Triplet found: ";
            for(int num:triplet){
                cout<<num<<" ";
            }
            cout<<endl;
        }
    }
}
//TC = O(n^2 + nlogn), SC = O(no. of triplets) for storing triplets
//Problem 2: 4Sum: Find and print all unique quadruplets in the array that add up to a target sum.
void FourSumBruteForce(int n,int arr[],int target){
    bool found=false;
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(arr[i]+arr[j]+arr[k]+arr[l]==target){
                        vector<int> quadruplet={arr[i],arr[j],arr[k],arr[l]};
                        sort(quadruplet.begin(),quadruplet.end()); // Sort to ensure uniqueness
                        s.insert(quadruplet); // Insert into set to avoid duplicates
                        found=true;
                    }
                }
            }
        }
    }
    vector<vector<int>> result(s.begin(),s.end());
    for(const auto& triplet:result){
        cout<<"Quadruplet found: ";
        for(int num:triplet){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    if(!found)
        cout<<"No such quadruplet found"<<endl;
}
//For better solution, we can use a hash map to store the indices of the elements.
void FourSumBetter(int n,int arr[],int target){
    bool found=false;
    set<vector<int>> s;
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        ump[arr[i]]=i; // Store the index of each element
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int complement=target-(arr[i]+arr[j]+arr[k]); // Find the complement
                if(ump.find(complement)!=ump.end() && ump[complement]!=i && ump[complement]!=j && ump[complement]!=k){
                    vector<int> quadruplet={arr[i],arr[j],arr[k],complement};
                    sort(quadruplet.begin(),quadruplet.end()); // Sort to ensure uniqueness
                    s.insert(quadruplet); // Insert into set to avoid duplicates
                    found=true;
                }
            }
        }
    }
    vector<vector<int>> result(s.begin(),s.end());
    for(const auto& triplet:result){
        cout<<"Quadruplet found: ";
        for(int num:triplet){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    if(!found)
        cout<<"No such quadruplet found"<<endl;
}
//For optimal solution, we can define a two-pointer approach after sorting the array same as in 3Sum.
void FourSumOptimal(int n,int arr[],int target){
    vector<vector<int>> result;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue; // Skip duplicates
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue; // Skip duplicates
            int left=j+1, right=n-1;
            while(left<right){
                int sum=arr[i]+arr[j]+arr[left]+arr[right];
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    vector<int> quadruplet={arr[i],arr[j],arr[left],arr[right]};
                    result.push_back(quadruplet);
                    left++;
                    right--;
                    while(left<right && arr[left]==arr[left-1]) left++; // Skip duplicates
                    while(left<right && arr[right]==arr[right+1]) right--; // Skip duplicates
                }
            }
        }
    } 
    if(result.empty()){
        cout<<"No quadruplet found"<<endl;
    }
    else{
        for(auto &quadruplet:result){
            cout<<"Quadruplet found: ";
            for(int num:quadruplet){
                cout<<num<<" ";
            }
            cout<<endl;
        }
    }
    //TC = O(n^3 + nlogn), SC = O(no. of quadruplets) for storing quadruplets
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //ThreeSumBruteForce(size, arr);
    //ThreeSumBetter(size, arr);
    //ThreeSumOptimal(size, arr);
    int target;
    cout<<"Enter the target sum for 4Sum: ";
    cin>>target;
    FourSumBruteForce(size,arr,target); 
    FourSumBetter(size,arr,target);
    FourSumOptimal(size,arr,target);
    return 0;
}