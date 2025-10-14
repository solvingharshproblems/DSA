#include <iostream>
using namespace std;
//Problem 1: Minimum number of platforms required for a railway station so that no train waits
//Given the arrival and departure times of trains, we have to find the minimum number of platforms required so that no train waits
//For Optimal Approach, we will sort the arrival and departure times separately and then use two pointers to traverse both arrays
void MinimumPlatforms(vector<int> arrival,vector<int> departure){
    int n=arrival.size();
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int i=1,j=0;
    int platforms=1;
    int maxPlatforms=1;
    while(i<n && j<n){
        if(arrival[i]<=departure[j]){
            platforms++;
            i++;
        }
        else{
            platforms--;
            j++;
        }   
        maxPlatforms=max(maxPlatforms,platforms);
    }
    cout<<"Minimum number of platforms required: "<<maxPlatforms<<endl;
} // TC=O(nlogn+nlogn+n) SC=O(1)
//Problem 2: Fractional Knapsack Problem
//Given the weights and values of n items, we have to put these items in a knapsack of capacity W to get the maximum total value in the knapsack
//For Optimal Approach, we will calculate the value/weight ratio for each item and sort the items in decreasing order of this ratio
//Then we will keep adding the items to the knapsack until we reach its capacity, if we cannot add the complete item, we will add the fractional part of it
void FractionalKnapsack(vector<int> weight,vector<int> value,int W){
    int n=weight.size();
    vector<pair<double,pair<int,int>>> arr(n);
    for(int i=0;i<n;i++){
        double ratio=(double)value[i]/(double)weight[i];
        arr[i]={ratio,{weight[i],value[i]}};
    }
    sort(arr.begin(),arr.end(),greater<pair<double,pair<int,int>>>());
    double totalValue=0.0;
    for(int i=0;i<n;i++){
        if(W==0){
            break;
        }
        if(arr[i].second.first<=W){
            W-=arr[i].second.first;
            totalValue+=arr[i].second.second;
        }
        else{
            totalValue+=arr[i].first*W;
            W=0;
        }
    }
    cout<<"Maximum total value in the knapsack: "<<totalValue<<endl;
} // TC=O(nlogn+n) SC=O(n) for storing the array
int main(){
    /*
    int n;
    cout<<"Enter the number of trains: ";
    cin>>n;
    vector<int> arrival(n);
    vector<int> departure(n);
    cout<<"Enter the arrival times of trains: ";
    for(int i=0;i<n;i++){
        cin>>arrival[i];
    }
    cout<<"Enter the departure times of trains: ";
    for(int i=0;i<n;i++){
        cin>>departure[i];
    }
    MinimumPlatforms(arrival,departure);
    */
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    cout<<"Enter the weights of items: ";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"Enter the values of items: ";
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int W;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>W;
    FractionalKnapsack(weight,value,W);
    return 0;
}