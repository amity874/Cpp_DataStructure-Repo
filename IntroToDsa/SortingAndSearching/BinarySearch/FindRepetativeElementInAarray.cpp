#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int calc(std::vector<int>&arr){
    int n=arr.size();
    int lo=0;
    int hi=n-1;
    int ans=0;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid){
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
    std::vector<int>arr={1,2,3,4,5,6,7,8,9,9};
    cout<<calc(arr);
    return 0;
}
