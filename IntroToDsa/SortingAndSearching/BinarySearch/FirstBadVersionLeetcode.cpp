#include<bits/stdc++.h>
using namespace std;
bool isBadVersion(int version);
int basVersion(int n){
    int lo=0;
    int hi=n;
    int ans=0;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(isBadVersion(mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
