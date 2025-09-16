#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Check for balanced parentheses in an expression
//For Optimal Approach, we can use a stack to keep track of opening brackets and ensure they are properly closed.
int isBalanced(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return 0;
            }
            char top=st.top();
            if((s[i]==')' && top=='(') || (s[i]=='}' && top=='{') || (s[i]==']' && top=='[')){
                st.pop();
            }
            else{
                return 0;
            }
        }
    }
    return st.empty();
} //TC=O(n) SC=O(n)
int main(){
    string s;
    cout<<"Enter the expression: ";
    cin>>s;
    if(isBalanced(s)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}