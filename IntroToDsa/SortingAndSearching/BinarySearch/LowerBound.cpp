#include<bits/stdc++.h>
using namespace std;
int search(std::vector<int>&a,int target){
    int lo=0;
    int hi=a.size()-1;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]>=target){
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
    std::vector<int>arr={5,6,34,56,78,78,90};
    cout<<search(arr,7);//first value >=target
    return 0;
}
