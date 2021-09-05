#include<bits/stdc++.h>
using namespace std;
int path=0;
void mazepath(int i,int j,int n,int m,string osf){
    //Base cases
    if(i==n-1 && j==m-1){
        path+=1;
        cout<<osf<<"\n";
        return;
    }
    if(i>=n or j>=m){
        return;
    }
    mazepath(i,j+1,n,m,osf+"D");
    mazepath(i+1,j,n,m,osf+"R");
    // mazepath(i+1,j+1,n,m,osf+"->")//for diagonal path
}
int main(int argc, char const *argv[])
{
    
    int n=3;
    int m=3;
    mazepath(0,0,n,m,"");
    cout<<path;
    return 0;
}
