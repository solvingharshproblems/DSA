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
//Problem 2: Candy
//There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute the candies to the children.
//For Brute Force Approach, we can declare a left and right array to keep track of the candies given to the children from left and right side respectively.
//We will traverse the ratings array from left to right and if the current rating is greater than the previous rating, we will increment the candy count for the current child by 1 more than the previous child.
//We will do the same for the right array by traversing the ratings array from right to left.
//Finally, we will take the maximum of the two arrays for each child and sum them up to get the total candies needed.
void CandyBruteForce(vector<int> ratings){
    int n=ratings.size();
    vector<int> left(n,1);
    vector<int> right(n,1);
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            left[i]=left[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            right[i]=right[i+1]+1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=max(left[i],right[i]);
    }
    cout<<"Minimum candies needed: "<<sum<<endl;
} // TC=O(3n) SC=O(2n)
//For Better Approach, we can use a single array to keep track of the candies given to the children.
//We will traverse the ratings array from left to right and if the current rating is greater than the previous rating, we will increment the candy count for the current child by 1 more than the previous child.
//Then we will traverse the ratings array from right to left and if the current rating is greater than the next rating, we will update the candy count for the current child to be the maximum of the current candy count and 1 more than the next child.
//Finally, we will sum up the candy array to get the total candies needed.
void CandyBetter(vector<int> ratings){
    int n=ratings.size();
    vector<int> candy(n,1);
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            candy[i]=candy[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            candy[i]=max(candy[i],candy[i+1]+1);
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=candy[i];
    }
    cout<<"Minimum candies needed: "<<sum<<endl;
} // TC=O(2n) SC=O(n)
//For Optimal Approach, we will use slope concept to keep track of the increasing and decreasing ratings.
//We will traverse the ratings array and keep track of the current slope.
//If the current rating is greater than the previous rating, we will increment the candy count for  the current child by 1 more than the previous child and update the peak value.
//If the current rating is less than the previous rating, we will decrement the candy count for the current child.
//If the candy count becomes 0, we will reset it to 1 and increment the peak value and add it to the total.
//If the current rating is equal to the previous rating, we will reset the candy count and peak value to 1 and add it to the total
void CandyOptimal(vector<int> ratings){
    int n=ratings.size();
    int sum=1,i=1;
    while(i<n){
        if(ratings[i]==ratings[i-1]){
            sum++;
            i++;
            continue;
        }
        int peak=1;
        while(i<n && ratings[i]>ratings[i-1]){
            peak++;
            sum+=peak;
            i++;
        }
        int down=1;
        while(i<n && ratings[i]<ratings[i-1]){
            sum+=down;
            down++;
            i++;
        }
        if(down>=peak) sum+=down-peak;
        else sum+=peak-1;
    }
    cout<<"Minimum candies needed: "<<sum<<endl;
} // TC=O(n) SC=O(1)
int main(){
    /*
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if(ValidStringBruteForce(s)) cout<<"The string is valid"<<endl;
    else cout<<"The string is not valid"<<endl;
    if(ValidStringOptimal(s)) cout<<"The string is valid"<<endl;
    else cout<<"The string is not valid"<<endl;
    */
    int n;
    cout<<"Enter the number of children: ";
    cin>>n;
    vector<int> ratings(n);
    cout<<"Enter the ratings of the children: ";
    for(int i=0;i<n;i++){
        cin>>ratings[i];
    }
    CandyBruteForce(ratings);
    CandyBetter(ratings);
    CandyOptimal(ratings);
    return 0;
}