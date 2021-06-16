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
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define loopprev(i,a,b) for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++)cout<<(arr[z])<<" ";
ll dp[105][105][2];
ll adjBC(int n,int k,int f){
	if(n==0)return 0;
	if(n==1){
		if(k==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[n][k][f]!=-1)return dp[n][k][f];
	ll retval=-1;
	if(f==1){
		retval=adjBC(n-1,k,0)+adjBC(n-1,k-1,1);
	}else{
		retval=adjBC(n-1,k,0)+adjBC(n-1,k,1);
	}
	return dp[n][k][f]=retval;
}
int main(int argc, char const *argv[])
{
	int p;
	cin>>p;
	while(p--){
		int num,n,k;
		cin>>num>>n>>k;
		memset(dp,-1,sizeof(dp));
		ll ans=adjBC(n,k,0);
		ans+=adjBC(n,k,1);
		cout<<num<<" "<<ans<<endl;
	}
	return 0;
}