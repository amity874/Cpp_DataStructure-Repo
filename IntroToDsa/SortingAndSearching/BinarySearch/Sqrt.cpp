#include<bits/stdc++.h>
using namespace std;
float search(int n,int precision){
    int lo=0;
    int hi=n;
  float ans=0.0;
    while (lo<=hi){
        /* code */
        int mid=lo+(hi-lo)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            lo=mid+1;
        }
        else{
            hi=mid-1;
            ans=hi;
        }
    }
   
    float incr=0.1;
    for(int i=0;i<=precision;i++){
        while((ans*ans)<=n){
            ans+=incr;
        }
        ans=ans-incr;
        incr=incr/10;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<search(n,3);
    return 0;
}
