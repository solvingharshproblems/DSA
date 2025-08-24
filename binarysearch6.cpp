#include <iostream>
#include <algorithm>
using namespace std;
//Problem 1:Find minimum no. of days to make m bouquets
bool Possible(int arr[],int n,int m,int k, int days){
    int count=0,bouquets=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=days){
            count++;
            if(count==k){
                bouquets++;
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    return bouquets>=m;
}
void DaysRequired(int n,int arr[],int m,int k){
    int low=*min_element(arr,arr+n);
    int mid,result=-1;
    int high=*max_element(arr,arr+n);
    if(m*k>n){
        cout<<"Not possible to make bouquets";
        return;
    }
    while(low<=high){
        mid=(low+high)/2;
        if(Possible(arr,n,m,k,mid)){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"The minimum days required to make "<<m<<" bouquets is: "<<result;
}
//TC = O(n log(max-min+1))
//Problem 2: Find the smallest divisor given a threshold
int SumofArray(int arr[],int n,int divisor){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)arr[i]/divisor);
    }
    return sum;
}
void SmallestDivisor(int n,int arr[],int threshold){
    int low=1,mid,result=-1;
    int high=*max_element(arr,arr+n);
    while(low<=high){
        mid=(low+high)/2;
        int sum=SumofArray(arr,n,mid);
        if(sum<=threshold){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"The smallest divisor is: "<<result;
} //TC = O(n log max(arr)
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    /*
    int m,k;
    cout<<"Enter the number of bouquets you want: ";
    cin>>m;
    cout<<"Enter the number of flowers in each bouquet: ";
    cin>>k;
    DaysRequired(size,arr,m,k);
    */
    int threshold;
    cout<<"Enter the threshold value: ";
    cin>>threshold;
    SmallestDivisor(size,arr,threshold);
    return 0;
}