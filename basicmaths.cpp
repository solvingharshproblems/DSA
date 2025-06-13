#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void extractingDigits(int n){
    while(n>0){
        int last_digit=n%10;
        cout<<last_digit<<endl;
        n=n/10;
    }
}
void countingDigits(int n){
    /*
    //method 1:
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    cout<<count<<endl;
    */
    //method 2:
    int cnt;
    if(n==0){
        cout<<"Undefined value.";
    }
    else{
        cnt=(int)(log10(n)+1);
        cout<<cnt;
    }
}
void reversingNumber(int n){
    while(n>0){
        int digit=n%10;
        if(digit==0){
            cout<<"";
        }
        else{
            cout<<digit;
        }
        n=n/10;
    }
}
void checkingPalindrome(int n){
    int original=n;
    int reversed=0;
    while(n>0){
        int digit=n%10;
        reversed=reversed*10+digit;
        n=n/10;
    }
    if(reversed==original){
        cout<<"It is a Palindrome.";
    }
    else{
        cout<<"No Palindrome.";
    }
}
void checkingPrime(int n){
    bool isPrime=true;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            isPrime=false;
            break;
        }
    }
    if(isPrime){
        cout<<"It is a prime number.";
    }else{
        cout<<"It is not a prime number.";
    }
}
void checkingArmstrong(int n){
    int armstrong=n;
    int num=0;
    while(n>0){
        int digit=n%10;
        num=num+(digit*digit*digit);
        n/=10;
    }
     if(num==armstrong){
        cout<<"It is an armstrong number.";
     }
     else{
        cout<<"It is not an armstrong number.";
    }
}
void checkingDivisors(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" Is a divisor of: "<<n<<endl;
        }
    }
}
void checkingHCF(int n1,int n2){
    int HCF=1;
    for(int i=min(n1,n2);i>1;i--){
        if((n1%i==0)&&(n2%i==0)){
            HCF=i;
            cout<<HCF;
            break;
        }
    }
}
//Or we can use EuclideanAlgorithmn to find it more faster
void EuclideanAlgorithmn(int n1,int n2){
    while((n1>0)&&(n2>0)){
        if(n1>n2){
            n1=n1%n2;
        }
        else{
            n2=n2%n1;
        }
    }
    if(n1==0){
        cout<<n2;
    }
    else{
        cout<<n1;
    }
}
int main(){
    int a,b;
    cout<<"Enter 1st number: ";
    cin>>a;
    cout<<"Enter 2nd number: ";
    cin>>b;
    EuclideanAlgorithmn(a,b);
    return 0;
}