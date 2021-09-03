#include<bits/stdc++.h>
using namespace std;
int search(std::vector<int>&a,int target){
    int lo=0;
    int hi=a.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]<target){
            lo=mid+1;
        }
        else if(a[mid]>target){
            hi=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={4,5,6,7,45,78,90};
    cout<<search(arr,45);
    return 0;
}
