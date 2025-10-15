#include <iostream>
using namespace std;
//Problem 1: Valid Parenthesis String
//Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//The following rules define a valid string:
//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//Any right parenthesis ')' must have a corresponding left parenthesis '('.
//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
//For Brute Force Approach, we can use recursion to return all the possible combinations of the string and check if any of them is valid.
bool ValidStringBruteForce(string s){
    int count=0;
    int index=0;
    if(count<0) return false;
    if(index==s.length()) return count==0;
    if(s[index]=='(') count++;
    else if(s[index]==')') count--;
    else{
        return ValidStringBruteForce(s.substr(index+1)) || ValidStringBruteForce(s.substr(index+1)) || ValidStringBruteForce(s.substr(index+1));
    }
    return ValidStringBruteForce(s.substr(index+1));
} // TC=O(3^n) SC=O(n) for recursion stack space
//For Optimal Approach, instead of count variable we will use a range between -1 and +1 to keep track of the possible number of open parenthesis.
//We will increment the lower bound when we encounter a ')' and decrement the upper bound when we encounter a '('.
//When we encounter a '*', we will increment the upper bound and decrement the lower bound.
//If at any point the upper bound becomes negative, we can return false as there are more ')' than '('.
//If the lower bound becomes negative, we can reset it to 0 as we can treat '*' as '('.
bool ValidStringOptimal(string s){
    int min=0,max=0;
    for(char c:s){
        if(c=='('){
            min++;
            max++;
        }
        else if(c==')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }
        if(max<0) return false;
        if(min<0) min=0;
    }
    return min==0;
} // TC=O(n) SC=O(1)
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if(ValidStringBruteForce(s)) cout<<"The string is valid"<<endl;
    else cout<<"The string is not valid"<<endl;
    if(ValidStringOptimal(s)) cout<<"The string is valid"<<endl;
    else cout<<"The string is not valid"<<endl;
    return 0;
}