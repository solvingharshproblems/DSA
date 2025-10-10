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
//Problem 2: Lemonade Change
//At a lemonade stand, each lemonade costs $5.
//Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).
//Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
//You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.
//Note that you don't have any change in hand at first.
//Return true if and only if you can provide every customer with correct change.
bool LemonadeChangeOptimal(vector<int> bills){
    int five=0,ten=0,twenty=0;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            five++;
        }
        else if(bills[i]==10){
            if(five>0){
                five--;
                ten++;
            }
            else{
                return false;
            }
        }
        else{
            if(ten>0 && five>0){
                ten--;
                five--;
                twenty++;
            }
            else if(five>=3){
                five-=3;
                twenty++;
            }
            else{
                return false;
            }
        }
    }
    return true;
} // TC=O(n) SC=O(1)
int main(){
    /*
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
    */
    int n;
    cout<<"Enter the number of customers: ";
    cin>>n;
    vector<int> bills(n);
    cout<<"Enter the bills of customers: ";
    for(int i=0;i<n;i++){
        cin>>bills[i];
    }
    if(LemonadeChangeOptimal(bills)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}