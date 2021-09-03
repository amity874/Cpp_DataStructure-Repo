#include<bits/stdc++.h>
using namespace std;
int Calc(int *a,int n){
    std::sort(a,a+n);
    int ans=0;  
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
    int upper1 = std::upper_bound(a,a+n,a[i]+a[j])-a;
            ans+=(n-upper1);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int a[]={5,2,9,6};
    cout<<Calc(a,4);
    return 0;
}