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
int main(){
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
    return 0;
}