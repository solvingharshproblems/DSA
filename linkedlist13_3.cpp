#include <iostream>
using namespace std;
//Problem 3: Design a browser history using linked list
class Node{
    public:
        string url;
        Node* next;
        Node* back;
        Node(){
            url="";
            next=nullptr;
            back=nullptr;
        }
        Node(string url1){
            url=url1;
            next=nullptr;
            back=nullptr;
        }
        Node(string url1,Node* next1,Node* back1){
            url=url1;
            next=next1;
            back=back1;
        }
};
class Browser{
    public:
        Node* current;
        Browser(string homepage){
            current=new Node(homepage);
        }
        void visit(string url){
            Node* newNode=new Node(url);
            current->next=newNode;
            newNode->back=current;
            current=newNode;
        }
        string back(int steps){
            while(steps > 0 && current->back != nullptr){
                current = current->back;
                steps--;
            }
            return current->url;
        }
}; //TC=O(n) where n is number of nodes in linked list
int main(){
    string homepage;
    cout<<"Enter homepage url: ";
    cin>>homepage;
    Browser* obj=new Browser(homepage);
    obj->visit("google.com");
    obj->visit("youtube.com");
    obj->visit("facebook.com");
    cout<<obj->back(1)<<endl;   
    cout<<obj->back(1)<<endl;
    obj->visit("linkedin.com");
    cout<<obj->back(2)<<endl;
    cout<<obj->back(7)<<endl;
    return 0;
}