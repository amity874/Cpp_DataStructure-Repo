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
int* countFlowers(int k){
	int *dp=new int[100005];
	dp[0]=1;
	for (int i = 1; i<= 100000; i++)
	{
		if(i<k)dp[i]=dp[i-1];
		else{
			dp[i]=(dp[i-1]%mod+(dp[i-k])%mod);
		}
	}
	for(int i=1;i<=100000;i++){
			dp[i]=(dp[i-1]%mod+(dp[i])%mod);//Prefix sum
	}
	return dp;
}
int main(int argc, char const *argv[])
{
	int t,k;
	cin>>t>>k;
	int *dp=countFlowers(k);
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
	}
	return 0;
}