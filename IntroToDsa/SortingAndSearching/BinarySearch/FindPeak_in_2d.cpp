#include<bits/stdc++.h>
// https://leetcode.com/problems/find-a-peak-element-ii/submissions/
using namespace std;
int findMax(std::vector<int>&a){
    int idx=0;
    int mx=0;
    for(int i=0;i<a.size();i++){
        if(mx<a[i]){
            mx=a[i];
            idx=i;
        }
    }
    return idx;
}
std::pair<int,int>search(std::vector<vector<int>>&a){
    int lo=0;
    int row=a.size();
    int col=a[0].size();
    int hi=row-1;
     int max_idx=0;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
         max_idx=findMax(a[mid]);
        if(a[mid][max_idx]<a[mid+1][max_idx]){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    // max_idx=findMax(a[lo]);
    return{lo,max_idx};
}

int main(int argc, char const *argv[])
{
    std::vector<vector<int>>arr={{-1,-1,-1,-1,-1},{-1,10,20,15,-1},{-1, 21, 30, 14, -1}, {-1, 7, 16, 32, -1}, {-1,-1,-1,-1,-1}};
    std::pair<int,int> p;
    p=search(arr);
    cout<<(p.first)<<" "<<(p.second);
    return 0;
}
