//Standard Template Library
#include <iostream>
#include <vector>
#include <string.h>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std; 
//Here we start with functions
void explainingPairs(){
    pair<int,int> p={1,2};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int,pair<double,float>> x={3,{4.55,5.4}};
    cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    pair<char,int> arr[]={{'A',1 },{'A',2 },{'B',3}};
    cout<<arr[0].first<<" "<<arr[2].second;
}
//Here we start with containers and iterators 
void explainingVectors(){
    vector<int> v(5);
    v.push_back(1); //it adds value in paranthesis as the last element 
    v.emplace_back(2); //it increases the size of the vector and pushes paranthesis's value at the back. It is faster than push back
    v.pop_back();//removes the last element from the vector
    v.size();//shows size of vector
    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);
    vector<int> v2(v);//copying a vector into another one
    //cout<<v.at(6); //method 1 for printing elements of a vector
    //cout<<v.back; //it is used for pointing at the last element of the vector
    //v.erase(v.begin()+1,v.begin()+3); in the paranthesis first part is for the start part to erase,
    // second part is the iteration right after the part to erase
    //v.insert(v.begin()+1,2,15); it will insert 2 values of 15 just after the 1st existing value in vector
    v.swap(v2);//swaps the value of v with v2
    v.clear();//clears the whole vector
    cout<<v.empty();//checks whether the vector is empty or not
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){// begin and end function accesses the address of the value stored 
        cout<<*it<<endl;//we need to use pointer to dereference it and give us the value instead of its address
    }
}
void tryingstring(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);
    cout<<"The string is: ";
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i;
    }
    cout<<endl<<"The reversed string is: ";
    for(auto i=s.rbegin();i!=s.rend();i++){
        cout<<*i;
    }
}
void explainingLists(){
    list<int>ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);//we can also add values in front in lists
    //all the rest of the functions are same as vectors
}
void explainingDeque(){
    deque<int>dq;
    //all the functions are exactly the same as lists
}
//all of these follows FIFO-First In First Out or LILO-Last In Last Out
void explainingStacks(){ //it follows LIFO-Last In First Out
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);
    cout<<st.top();//displays the top/last-inserted element
    st.pop();//removes "4" as the last-inserted element
    cout<<st.size();
    cout<<st.empty();
}
void explainingQueues(){ //another FIFO follower
    queue<int>q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    q.back()+=5;
    cout<<q.back();
    cout<<q.front();
    q.pop();
    cout<<q.front();
}
void explainingPriorityQueues(){ //Largest Elements stays on the top
    priority_queue<int>pq; //Max Heap
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.emplace(10);
    cout<<pq.top(); // 10,8,5,3
    //To store smallest element on top
    priority_queue<int,vector<int>,greater<int>> pqs; //Min Heapj
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.emplace(10);
    cout<<pq.top(); //3,5,8,10
}
void explainingSets(){ //stores in increasing order and only unique values
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.emplace(3);
    /*
    auto it=s.find(2);
    auto its=s.find(5);//as the value is not in set,it will return s.end() value
    if (its != s.end()) {
        cout << *its;
    } else {
        cout << "Element not found"; // This will run
    } */
    // or use 
    int cnt=s.count(2); //will return 0 if not found
    s.erase(s.find(2),s.find(4));//erases 2 and 3 from the set
}
void explainMultiSets(){ // stores in increasing order but allows duplicates
    multiset<int>ms;
    ms.insert(1);
    ms.insert(1);
    ms.erase(1);//erases all the 1 present in multiset
    int cnt=ms.count(1);//counts the no. of 1 
    ms.erase(ms.find(1));//erases only first 1 as it erases the address
    //ms.erase((ms.find(1)),(ms.find(1)+2));erases 1st and 2nd 1
    //rest same as sets
}
void explainingUnorderedSets(){ //stores unique values but in a random order
    unordered_set<int>us;
    //rest same as sets just lower bound and upper bound doesnt works at all
}
void explainingMaps(){ // stores unique keys in sorted order
    map<int,int> m;
    m[1]=2;
    m.insert({3,4});
    m.emplace(5,6);
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    auto its=m.find(3);
    cout<<its->second;
    //rest functions are same
}
void explainingMultiMaps(){
    // same diff as sets and multisets
}
void explainingUnorderedMaps(){
    // same diff as sets and unorderedsets
}
//Here we will start with Algorithmns
bool comp(pair<int,int> p1,pair<int,int>p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    return p1.first > p2.first;
}
void explainingSort(){
    /*
    vector<int>v={1,4,3,7,6,20,12};
    sort(v.begin(),v.end());
    for(auto it:v){
        cout<<it<<" ";
    } For reverse sorting
    sort(v.begin(),v.end(),greater<int>());
    for(auto it:v){
        cout<<it<<" ";
    } 
    //what if i wanted to print numbers in my sorted order */
    pair<int,int> v[]={{1,2},{2,1},{4,1}};
    sort(v,v+3,comp);
    for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
void explainingExtra(){
    //Printing all the permutations of a string possible
    string s="123";
    do{
        cout<<s<<endl;
    }
    while(next_permutation(s.begin(),s.end()));
    //to find max or min element in an array
    int a[]={1,2,3,4,5};
    int maxim=*max_element(a,a+4);
    cout<<maxim<<endl;
    int minim=*min_element(a,a+4);
    cout<<minim<<endl;
}
int main(){
    explainingExtra();
    return 0;
}