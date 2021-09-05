#include<bits/stdc++.h>
using namespace std;
void Path(int n,int i,string osf){
    if(i>=n){
        return;
    }
    if(i==n-1){
        cout<<osf<<"\n";
        return;
    }
    for(int j=1;j<=6;j++){
        Path(n,i+j,osf+to_string(j));
    }
}
int main(int argc, char const *argv[])
{
    Path(4,0,"");
    return 0;
}
