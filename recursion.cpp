#include <iostream>
using namespace std;
int mycount=0;//global variable
void Count(){
    if(mycount==4){
        return;
    }
    else{
        cout<<mycount<<endl;
        mycount++;
        Count();
    }
}
int main(){
    Count();
    return 0;
}