#include <iostream>

using namespace std;
//Initial Approach
void FindingKey(int size,int arr[],int key){
    int Count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            Count++;
        }
    }
    if(Count==0){
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"Key found "<<Count<<" times.";
    }
}
//Hashing Approach
void Hashing(int n,int arr[],int hash[],int q){
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    while(q--){
        int number;
        cout<<"Enter the number to count: ";
        cin>>number;
        cout<<hash[number]<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    /*
    int key;
    cout<<"Enter the key you want: ";
    cin>>key;
    FindingKey(n,arr,key); */
    int hash[13]={};
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    Hashing(n,arr,hash,q);
    return 0;
}