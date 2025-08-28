#include <iostream>
#include <vector>
using namespace std;
//Problem 1: Find median of 2 sorted arrays of different sizes
void Median(int n,int arr1[],int m,int arr2[]){
    int low=0,high=n,mid1,mid2;
    int l1=INT_MIN,l2=INT_MIN;
    int r1=INT_MAX,r2=INT_MAX;
    if(n>m){
        Median(m,arr2,n,arr1);
        return;
    }
    int left=(n+m+1)/2;
    while(low<=high){
        mid1=(low+high)/2;
        mid2=left-mid1;
        if(mid1<n){
            r1=arr1[mid1];
        }
        if(mid2<m){
            r2=arr2[mid2];
        }
        if(mid1-1>=0){
            l1=arr1[mid1-1];
        }
        if(mid2-1>=0){
            l2=arr2[mid2-1];
        }
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0){
                cout<<"The median is: "<<(max(l1,l2)+min(r1,r2))/2.0<<endl;
            }
            else {
                cout<<"The median is: "<<max(l1,l2)<<endl;
            }
            return;
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else {
            low=mid1+1;
        }
    }
} //TC=O(log(min(n,m)))
//Problem 2: Kth element of 2 sorted arrays
void KthElement(int n,int arr1[],int m,int arr2[],int k){
    if(n>m){
        KthElement(m,arr2,n,arr1,k);
        return;
    }
    int low=max(0,k-m),high=min(k,n);
    int l1=INT_MIN,l2=INT_MIN;
    int r1=INT_MAX,r2=INT_MAX;
    while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=k-mid1;
        if(mid1<n){
            r1=arr1[mid1];
        }
        if(mid2<m){
            r2=arr2[mid2];
        }
        if(mid1-1>=0){
            l1=arr1[mid1-1];
        }
        if(mid2-1>=0){
            l2=arr2[mid2-1];
        }
        if(l1<=r2 && l2<=r1){
            cout<<"The "<<k<<"th element is: "<<max(l1,l2)<<endl;
            return;
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else {
            low=mid1+1;
        }
    }
} //TC=O(log(min(n,m)))
int main(){
    int size1;
    cout<<"enter the size of 1st array: ";
    cin>>size1;
    int arr1[size1];
    cout<<"enter the elements of array: ";
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    int size2;
    cout<<"Enter the size of 2nd array: ";
    cin>>size2;
    int arr2[size2];
    cout<<"enter the elements of array: ";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    /*
    Median(size1,arr1,size2,arr2);
    */
    int k;
    cout<<"Enter the kth element you want to find: ";
    cin>>k;
    KthElement(size1,arr1,size2,arr2,k);
    return 0;
}