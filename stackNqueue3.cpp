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
//Problem 2: Designing a min stack that supports getMin() in O(1) time and O(1) space
//For Brute Force Approach we will declare a class stack and define a min function which will return the minimum element in the stack by traversing the entire stack.
class MinStack{
    stack<int> st;
    public:
    void push(int x){
        st.push(x);
    }
    void pop(){
        if(!st.empty()){
            st.pop();
        }
    }
    int top(){
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    int getMin(){   
        if(st.empty()){
            return -1;
        }
        int minEle=st.top();
        stack<int> temp=st;
        while(!temp.empty()){
            minEle=min(minEle,temp.top());
            temp.pop();
        }
        return minEle;
    }
}; //TC=O(n) SC=O(n)
//For Optimal Approach we will use an auxiliary stack to keep track of the minimum elements.
class MinStackOptimal{
    stack<int> st;
    stack<int> minSt;
    public:
    void push(int x){
        st.push(x);
        if(minSt.empty() || x<=minSt.top()){
            minSt.push(x);
        }
    }
    void pop(){
        if(!st.empty()){
            if(st.top()==minSt.top()){
                minSt.pop();
            }
            st.pop();
        }
    }
    int top(){
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    int getMin(){   
        if(minSt.empty()){
            return -1;
        }
        return minSt.top();
    }
}; //TC=O(1) SC=O(n) 

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
    MinStackOptimal ms;
    ms.push(3);
    ms.push(5);
    ms.push(2);
    ms.push(1);
    ms.push(9);
    ms.push(7);
    cout<<"Top element: "<<ms.top()<<endl; 
    cout<<"Minimum element: "<<ms.getMin()<<endl;
    return 0;
}