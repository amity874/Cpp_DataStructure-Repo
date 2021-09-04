#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int calc(int n){///for bricks size 1*1*1
    int lo=1;
    int hi=n;
    int ans=0;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if((mid*(mid+1))/2<n){
            lo=mid+1;
            ans=lo;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int calc1(int n){///for bricks size 2*2*2
    int lo=1;
    int hi=n;
    int ans=0;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(pow((mid*(mid+1))/2,2)<n){
            lo=mid+1;
            ans=lo;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n=3;
    cout<<calc1(n);
    return 0;
}
