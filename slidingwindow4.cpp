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
//Problem 2: Longest repeating character replacement
//For Brute Force Approach, we can generate all substrings and check if we can replace k characters to make all characters same. If we can, we can update the maxLength
void LongestRepeatingCharacterBruteForce(string s, int k){
    int n=s.size();
    int maxLength=0;
    for(int i=0;i<n;i++){
        int hash[26]={0};
        int maxCount=0;
        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxCount=max(maxCount,hash[s[j]-'A']);
            if(j-i+1-maxCount<=k){
                maxLength=max(maxLength,j-i+1);
            }
        }
    }
    cout<<"Longest repeating character replacement is: "<<maxLength<<endl;
} // TC=O(n^2) SC=O(1)
//For Better Approach, we can use sliding window technique
void LongestRepeatingCharacterBetter(string s, int k){
    int left=0;
    int right=0;
    int n=s.size();
    int hash[26]={0};
    int maxCount=0;
    int maxLength=0;
    while(right<n){
        hash[s[right]-'A']++;
        maxCount=max(maxCount,hash[s[right]-'A']);
        while(right-left+1-maxCount>k){
            hash[s[left]-'A']--;
            left++;
        }
        maxLength=max(maxLength,right-left+1);
        right++;
    }
    cout<<"Longest repeating character replacement is: "<<maxLength<<endl;
} // TC=O(2n) SC=O(1)
//For Optimal Approach, we will reduce the time complexity of better approach by removing the inner while loop
void LongestRepeatingCharacterOptimal(string s, int k){
    int left=0;
    int right=0;
    int n=s.size();
    int maxCount=0;
    int maxLength=0;
    int hash[26]={0};
    while(right<n){
        hash[s[right]-'A']++;
        maxCount=max(maxCount,hash[s[right]-'A']);
        if(right-left+1-maxCount>k){
            hash[s[left]-'A']--;
            left++;
        }
        maxLength=max(maxLength,right-left+1);
        right++;
    }
    cout<<"Longest repeating character replacement is: "<<maxLength<<endl;
} // TC=O(n) SC=O(1)
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    /*
    CountSubstringsBruteForce(s);
    CountSubstringsOptimal(s);
    */
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    LongestRepeatingCharacterBruteForce(s,k);
    LongestRepeatingCharacterBetter(s,k);
    LongestRepeatingCharacterOptimal(s,k);
    return 0;
}