#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007;
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define mid(low,hi) (lo+(hi-lo)/2);
struct job
{
  ll start,end,profit;
};
bool cmp(job a,job b){
  return (a.end<b.end);
}
ll BinarySearch(job Arr[],int i){
  int lo=0,hi=i-1;
  while(lo<=hi){
    int mid=mid(lo,hi);
    if(Arr[mid].end<Arr[i].start){
      if(Arr[mid+1].end<Arr[i].start){
        lo=mid+1;
      }
      else{
        return mid;
      }
    }else{/* code */
      hi=mid-1;
    }
  }
  return -1;
}
int main(){
  ll n;
  cin>>n;
  struct job Arr[n];
  for (int i = 0; i <n; i++)
  {
    cin>>Arr[i].start>>Arr[i].end>>Arr[i].profit;
  }
  sort(Arr,Arr+n,cmp);
  vi dp(n,0);
  dp[0]=Arr[0].profit;
  for (int i = 1; i < n; i++)
  {
    ll incl=Arr[i].profit;
    int idx=BinarySearch(Arr,i);
    if(idx!=-1){
      incl+=dp[idx];
    }
    ll excl=dp[i-1];
    dp[i]=max(incl,excl);
  }
  cout<<dp[n-1];
  return 0;
}
