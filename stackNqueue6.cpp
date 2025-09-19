#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Asteroid Collision
//We need to find the state of the asteroids after all collisions.
//For Optimal Approach we will use a stack to keep track of the asteroids that are still moving.
void asteroidCollisionOptimal(int arr[], int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            s.push(arr[i]);
        }
        else{
            while(!s.empty() && s.top()>0){
                if(s.top()<abs(arr[i])){
                    s.pop();
                }
                else if(s.top()==abs(arr[i])){
                    s.pop();
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<"State of asteroids after all collisions: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
} //TC=O(2n) SC=O(n)
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    asteroidCollisionOptimal(arr, n);
    cout<<endl;
    return 0;
}