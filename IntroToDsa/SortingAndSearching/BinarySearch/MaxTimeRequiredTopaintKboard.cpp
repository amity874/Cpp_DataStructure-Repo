#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int possiblePainter(std::vector<int>&arr,int mid){
    int s=0;
    int n=arr.size();
    int painter=1;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s>mid){
            s=arr[i];
            painter++;
        }
    }
    return painter;
}
int main(int argc, char const *argv[]){
    std::vector<int>board={10,10,10,10};
    int painter=2;
    int n=board.size();
    int s=0;
    int m=0;
    for(int i=0;i<n;i++){
        m=max(board[i],m);
        s+=board[i];
    }
    int lo=m;
    int hi=s;
    int ans=0;
    while (lo<=hi){
       int mid=lo+(hi-lo)/2;
       int total=possiblePainter(board,mid);
       if(total<=painter){
           hi=mid-1;
           ans=mid;
       }
       else{
           lo=mid+1;
       }
    }
    cout<<ans;
    return 0;
}
