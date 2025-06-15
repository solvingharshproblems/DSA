#include <iostream>
#include <map>
#include <unordered_map> //Will work same as map in this situation just not in sorted order
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
//If we need to store a bigger value than 10^6 for int we can store 10^7 by declaring array as a global variable.
void CharHashing(int n,char arr[],int hashh[],int q){
    for(int i=0;i<n;i++){
        hashh[arr[i]]+=1;
    }
    while(q--){
        char ch;
        cout<<"Enter the character to count: ";
        cin>>ch;
        cout<<hashh[ch]<<endl;
    }
}
//If we need to store a bigger value than 10^7 we cannot do that in array that time we use maps and unordered maps
void MapHashing(int n,int arr[],int q){
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    while(q--){
        int number;
        cin>>number;
        cout<<mp[number]<<endl;
    }
}
void MapCharHashing(int n,char arr[],int q){
    unordered_map<char,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    while(q--){
        char ch;
        cout<<"Enter the character to count: ";
        cin>>ch;
        cout<<mpp[ch]<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    char arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    /*
    int key;
    cout<<"Enter the key you want: ";
    cin>>key;
    FindingKey(n,arr,key); 
    int hash[13]={};
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    Hashing(n,arr,hash,q); 
    int hashh[256]={0};
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    CharHashing(n,arr,hashh,q); 
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    MapHashing(n,arr,q); */
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    MapCharHashing(n,arr,q);
    return 0;
}