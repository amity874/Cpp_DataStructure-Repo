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
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++)cout<<(arr[z])<<" "
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vi arr(n,0);
	loop(i,0,n-1){
		cin>>arr[i];
	}
	vi dp(n,1);
	dp[0]=1;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(arr[i]>arr[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n-1];
return 0;
}