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
ll start[1000005],temp[1000005],coin[1000005];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<int> arr(n,0);
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	std::vector<int > dp(n,0);
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);
	for (int i = 2; i <n ; i++)
	{
		dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
	}
	cout<<dp[n-1];
	return 0;
}