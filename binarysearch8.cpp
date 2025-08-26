#include <iostream>
using namespace std;
//Problem 1: Aggresive Cows
//Find a configuration, such that minimum distance between 2 cows is maximized
bool CanWePlace(int arr[],int n,int cows,int minDist){
    int lastPos = arr[0];
    cows--;
    for(int i = 1;i<n;i++){
        if(arr[i]-lastPos>=minDist){
            lastPos=arr[i];
            cows--;
        }
        if(cows==0) return true;
    }
    return false;
}
void AggresiveCows(int arr[],int n,int cows){
    int low=0,mid;
    int high=arr[n-1]-arr[0];
    int result=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(CanWePlace(arr,n,cows,mid)){
            result=mid;
            low=mid+1;
        } 
        else {
            high=mid-1;
        }
    }
    cout<<"The largest minimum distance is: "<<result<< endl;
} //TC = O(n log m) + O(n)
//Problem 2: Allocate Books
//Find a configuration, such that maximum number of pages assigned to a student is minimized
bool CanWeAllocate(int arr[],int n,int s,int minPages){
    int studentCount=1;
    int pagesAllocated=0;
    for(int i=0;i<n;i++){
        if(pagesAllocated+arr[i]>minPages){
            studentCount++;
            pagesAllocated=arr[i];
            if(studentCount>s) return false;
        }
        else {
            pagesAllocated+=arr[i];
        }
    }
    return true;
}
void BooksAllocation(int n,int arr[],int s){
    int low=arr[n-1];
    int high=0,mid,result=-1;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    while(low<=high){
        mid=(low+high)/2;
        if(CanWeAllocate(arr,n,s,mid)){
            result=mid;
            high=mid-1;
        } 
        else{
            low=mid+1;
        }
    }
    cout<<"The minimum number of pages is: "<<result<< endl;
} //TC = O(n log m) + O(n) 
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
    int cows;
    cout<<"Enter the number of cows: ";
    cin>>cows;
    AggresiveCows(arr,size,cows);
    */
    int s;
    cout<<"Enter the number of students: ";
    cin>>s;
    BooksAllocation(size,arr,s);
    return 0;
}