#include<bits/stdc++.h>
using namespace std;
bool possible(int n,int x,int y,int mid){
    return (mid/x+mid/y)>=n-1;
}
// tc=o(log(max(x,y)*n))
int Copy(int n,int x,int y){
    int lo=0;
    int hi=std::max(x,y)*n;
    int ans=0;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(n,x,y,mid)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans+std::min(x,y);    
}
int main(int argc, char const *argv[])
{
    
    int n;
    int x;
    int y;
    cin>>n>>x>>y;
    cout<<Copy(n,x,y);
    return 0;
}
