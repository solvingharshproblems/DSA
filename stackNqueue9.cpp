#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Online Stock Span Problem
//We need to return the possible integer value of maximum consicutive days for which the stock price is less than or equal to current price
//For Optimal Approach part 1 we can declare a class with dynamic array and for each new price we can iterate backwards to count the number of days
class StockSpanner1{
    stack<pair<int,int>> s; //pair of price and span
    public:
        StockSpanner1(){
        }
        int next(int price){
            int count=1;
            while(!s.empty() && s.top().first<=price){
                count+=s.top().second;
                s.pop();
            }
            s.push({price,count});
            return count;
        }
}; //TC=Θ(1) or O(n) || SC=O(n)
//For Optimal Approach part 2 we can use stack to store the price and the span of that price using the logic of previous greater element
class StockSpanner2{
    stack<pair<int,int>> st; //pair of price and span
    int index=-1;
    public:
        StockSpanner2(){
            index=-1;
        }
        int next(int price){
            index++;
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            int ans=index-(st.empty()?-1:st.top().second);
            st.push({price,index});
            return ans;
        }
}; //TC=Θ(1) or O(n) || SC=O(n)
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    StockSpanner2* obj=new StockSpanner2();
    for(int i=0;i<size;i++){
        int price;
        cout<<"Enter the price of stock on day "<<i+1<<": ";
        cin>>price;
        cout<<"The stock span for day "<<i+1<<" is: "<<obj->next(price)<<endl;
    }
    delete obj;
    return 0;
}