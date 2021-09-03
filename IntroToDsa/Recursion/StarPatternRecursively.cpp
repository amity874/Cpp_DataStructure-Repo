#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
void Pattern1(int n,int i){
    if(n==0){
        return;
    }
    if(i<n){
        cout<<"*";//self work
        Pattern1(n,i+1);//recursion
    }
    else{
        //this will change the row
        cout<<"\n";
        Pattern1(n-1,0);
    }
}
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    Pattern1(n,0);
    return 0;
}
