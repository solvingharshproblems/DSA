#include <iostream>
using namespace std;
void blockpattern(int a){
    for(int i=0;i<a;i++){
        for(int j=0;j<=a;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void increasingorderpattern(int b){
    for(int i=0;i<b;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void increasingnumberpattern(int c){
    for(int i=0;i<c;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void decreasingnumberpattern(int d){
    for(int i=d;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void decreasingorderpattern(int e){
    for(int i=e;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pyramidpattern(int f){
    for(int i=1;i<=f;i++){
        for(int space=1;space<=f-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void reversepyramidpattern(int g){
    for(int i=g;i>=1;i--){
        for(int space=1;space<=g-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void diamondpattern(int h){
    for(int i=1;i<=h;i++){
        for(int space=1;space<=h-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=h;i>=1;i--){
        for(int space=1;space<=h-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void arrowpattern(int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=k;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void binarypattern(int l){
    int start=1;
    for(int i=0;i<l;i++){
        if(i%2==0){
            start=1;
        }
        else{
            start=0;
        }
        for(int j=0;j<i;j++){
            cout<<start;
            start=1-start;
        }
        cout<<endl;
    }
}
void increasingcrownpattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int space=1;space<=2*(n-i);space++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}
void newnumberpattern(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num;
            num+=1;
        }
        cout<<endl;
    }
}
void increasingCharpattern(int n){
    for(int i=0;i<=n;i++){
        for(char j='A';j<='A'+i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void decreasingCharpattern(int n){
    for(int i=n;i>=0;i--){
        for(char j='A';j<='A'+i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void newCharpattern(int n){
    for(int i=0;i<=n;i++){
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch;
        }
        cout<<endl;
    }
}
void Charpyramidpattern(int n){
    for(int i=1;i<=n;i++){
        for(int space=1;space<=n-i;space++){
            cout<<" ";
        }
        char ch='A';
        int breakpoint=(2*i-1)/2;
        for(int j=1;j<=2*i-1;j++){
            cout<<ch;
            if(j<=breakpoint)ch++;
            else ch--;
        }
        for(int space=1;space<=n-i;space++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void reverseincreasingcharpattern(int n){
    for(int i=0;i<n;i++){
        char ch='E';
        for(char character=ch-i;character<=ch;character++){
            cout<<character<<" ";
        }
        cout<<endl;
    }
}
void hollowdiamondpattern(int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int space=1;space<=2*(n-i);space++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl; 
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int space=1;space<=2*(n-i);space++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void butterflypattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int space=1;space<=2*(n-i);space++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int space=1;space<=2*(n-i);space++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl; 
    }
}
void boxpattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (i==1||i ==n||j==1||j==n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void decreasingnumberblockpattern(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int bottom=(2*n-2)-i;
            cout<<(n-min(min(top,bottom),min(right,left)));
        }
        cout<<endl; 
    }
}
void newpattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"$";
        }
        cout<<endl;
    }
}
int main(){
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        int n;
        cin>>n;
        //blockpattern(n);
        //increasingorderpattern(n);
        //increasingnumberpattern(n);
        //decreasingnumberpattern(n);
        //decreasingorderpattern(n);
        //pyramidpattern(n);
        //reversepyramidpattern(n);
        //diamondpattern(n);
        //arrowpattern(n);
        //binarypattern(n);
        //increasingcrownpattern(n);
        //newnumberpattern(n);
        //increasingCharpattern(n);
        //decreasingCharpattern(n);
        //newCharpattern(n);
        //Charpyramidpattern(n);
        //reverseincreasingcharpattern(n);
        //hollowdiamondpattern(n);
        //butterflypattern(n);
        //boxpattern(n);
        //decreasingnumberblockpattern(n);
        newpattern(n);
    }
    return 0;
}