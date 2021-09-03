#include<bits/stdc++.h>
using namespace std;
int search(std::vector<int>&a){
    int lo=0;
    int hi=a.size()-1;
    int ans=-1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]>a[mid+1]){
            //decreasing curve
            //int this case our peak element lie into left side
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return lo;
}
int main(int argc, char const *argv[])
{
    std::vector<int>a={1,2,1,3,5,6,4};
    //tc=0(logn)
    cout<<search(a); 
    return 0;
}
