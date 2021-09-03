#include<bits/stdc++.h>
using namespace std;
void printinc(int n){
    if(n==0){
        return;
    }
    printinc(n-1);
   cout<<n;
}
void printdec(int n){
    if(n==0){
        return;
    }
    cout<<n;
    printdec(n-1);
}
void printincDec(int n){
     if(n==5){
        return;
    }
    printincDec(n-1);
    cout<<n;
}
int main(int argc, char const *argv[])
{
    /* code */
    printincDec(5);
    return 0;
}
