#include <iostream>
using namespace std;
//Problem 1: Assign Cookies
//Assume you are an awesome parent and want to give your children some cookies. 
//But, you want to be fair and give each child the least number of cookies possible.
//Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
//and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
//Your goal is to maximize the number of your content children and output the maximum number.
//For Optimal Approach, we will assign smallest cookie to the least greedy child
void AssignCookiesOptimal(vector<int> g,vector<int> s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int n=g.size();
    int m=s.size();
    int i=0,j=0;
    int count=0;
    while(i<n && j<m){
        if(s[j]>=g[i]){
            count++;
            i++;
        }
        j++;
    }
    cout<<"Maximum number of content children: "<<count<<endl;
} // TC=O(nlogn+mlogm+n+m) SC=O(1)
int main(){
    int n;
    cout<<"Enter the number of children: ";
    cin>>n;
    vector<int> g(n);
    cout<<"Enter the greed factors of children: ";
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int m;
    cout<<"Enter the number of cookies: ";
    cin>>m;
    vector<int> s(m);
    cout<<"Enter the sizes of cookies: ";
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    AssignCookiesOptimal(g,s);
    return 0;
}