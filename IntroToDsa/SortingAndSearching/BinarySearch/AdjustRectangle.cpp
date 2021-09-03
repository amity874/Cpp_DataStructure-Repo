#include<bits/stdc++.h>
using namespace std;
bool possible(int mid,int w,int h,int n){
    return (mid/h)*(mid/w)>=n;
}
int rectangle(int w,int h,int n){
    int lo=0;
    int hi=std::max(w,h)*n;
    int ans=0;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(mid,w,h,n)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n=10;
    int w=2;
    int h=3;
    cout<<rectangle(w,h,n);
    return 0;
}
