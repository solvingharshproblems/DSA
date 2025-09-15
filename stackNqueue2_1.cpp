//What is an operator/operand 
//Operators are special symbols that perform specific operations on one, two, or three operands and then return a result.
//Operands are the objects or values that operators act upon.
//What is priority of operators
//Operator precedence determines the order in which operators are evaluated in expressions. Operators with higher precedence are
//evaluated before operators with lower precedence.
//What is infix expression
//Infix notation is the common arithmetic and logical formula notation, in which operators are written in
//What is postfix expression
//Postfix notation, also known as Reverse Polish Notation (RPN), is a mathematical
//notation in which every operator follows all of its operands. It is used to eliminate the need for parentheses. It is used in stack-based and certain programming languages.
//What is a prefix expression
//Prefix notation, also known as Polish Notation, is a mathematical notation in which every operator precedes all of its operands.
//It is used to eliminate the need for parentheses in expressions. It is used in tree traversal algorithms and certain programming languages.
#include <iostream>
using namespace std;
int priority(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
//Infix to Postfix conversion
string InfixToPostfix(string s){
    int i=0;
    stack<char> st;
    string ans="";
    while(i<s.length()){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            ans+=s[i];
            i++;
        }
        else if(s[i]=='('){
            st.push(s[i]);
            i++;
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            i++;
        }
        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
} //TC=O(2n) SC=O(2n)
//Infix to Prefix conversion
string InfixToPrefix(string s){
    int i=0;
    stack<char> st;
    string ans="";
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    while(i<s.length()){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            ans+=s[i];
            i++;
        }
        else if(s[i]=='('){
            st.push(s[i]);
            i++;
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            i++;
        }
        else{
            while(!st.empty() && priority(s[i])<priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
} //TC=O(3n) SC=O(n)
//Postfix to Infix conversion
string PostfixToInfix(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp="("+op2+s[i]+op1+")";
            st.push(temp);
        }
    }
    return st.top();
} //TC=O(n) SC=O(n)
//Prefix to Infix conversion
string PrefixToInfix(string s){
    stack<string> st;
    for(int i=s.length()-1;i>=0;i--){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp="("+op1+s[i]+op2+")";
            st.push(temp);
        }
    }
    return st.top();
} //TC=O(n) SC=O(n)
int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    cout<<"Infix Expression: "<<s<<endl;
    cout<<"Postfix Expression: ";
    cout<<InfixToPostfix(s)<<endl;
    cout<<"Prefix Expression: ";
    cout<<InfixToPrefix(s)<<endl;
    string p="ab+cd^e-fgh*+^*i-";
    cout<<"Postfix Expression: "<<p<<endl;
    cout<<"Infix Expression: ";
    cout<<PostfixToInfix(p)<<endl;
    string q="-+a*b^-^cde+f*ghi";
    cout<<"Prefix Expression: "<<q<<endl;
    cout<<"Infix Expression: ";
    cout<<PrefixToInfix(q)<<endl;
    return 0;
}