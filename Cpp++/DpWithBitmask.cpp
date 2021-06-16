#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define mid(low,hi) (lo+(hi-lo)/2)
int CountSetbits(int i){
	int count=0;
	while(n>0){
		 n=n&(n-1);
		 count++;
	}
	return count;
}
ll mincost(vector<vector<ll>> cost){
	int n=cost.size();
	vector<ll> dp(1<<n,INT_MAX);
	dp[0]=0;
	for (int mask = 0; i < (1<<n); i++){
		int worker=CountSetbits(mask);
		for (int j = 0; j < n;j++){
			if(((mask>>j)&1)==1){
				continue;
			}else{
				dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[worker][j]);
			}
		}
	}
	return dp[(1<<n)-1];
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vi<<vi>>arr(n,vi(n,0));
// cout<<mincost	
	return 0;
}