#include <iostream>
using namespace std;
//Problem 1: Number of substrings containing all three characters
//For Brute Force Approach, we can generate all substrings and check if they contain all three characters. If they do, we can update the count
void CountSubstringsBruteForce(string s){
    int n=s.size();
    int count=0;
    int hash[3]={0};
    for(int i=0;i<n;i++){
        hash[0]=0;
        hash[1]=0;
        hash[2]=0;
        for(int j=i;j<n;j++){
            if(s[j]=='a'){
                hash[0]++;
            }
            else if(s[j]=='b'){
                hash[1]++;
            }
            else if(s[j]=='c'){
                hash[2]++;
            }
            if(hash[0]>0 && hash[1]>0 && hash[2]>0){
                count++;
            }
        }
    }
    cout<<"Count of substrings containing all three characters is: "<<count<<endl;
} // TC=O(n^2) SC=O(1)
//For Optimal Approach, we can use sliding window technique
void CountSubstringsOptimal(string s){
    int left=0;
    int right=0;
    int n=s.size();
    int hash[3]={0};
    int count=0;
    for(int i=0;i<n;i++){
        hash[s[i]-'a']=i;
        if(hash[0]>0 && hash[1]>0 && hash[2]>0){
            int minIndex=min(hash[0],min(hash[1],hash[2]));
            count+=minIndex+1;
        }
    }
    cout<<"Count of substrings containing all three characters is: "<<count<<endl;
} // TC=O(n) SC=O(1)
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    CountSubstringsBruteForce(s);
    CountSubstringsOptimal(s);
    return 0;
}