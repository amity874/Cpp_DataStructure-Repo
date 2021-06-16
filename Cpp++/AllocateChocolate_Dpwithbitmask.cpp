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
int CountSetbits(int n){
	int count=0;
	while(n>0){
		n=n&(n-1);
		count++;
	}
	return count;
}
int AllocateChocolate(vector<vector<int>> &like){
	int n=like.size();
	vector<ll>dp(1<<n,0);
	dp[(1<<n)-1]=1;
	for(int mask=((1<<n)-2);mask>=0;mask--){
		int kid=CountSetbits(mask);
		for(int chocolate=0;chocolate<n;chocolate++){
			if(like[kid][chocolate]&&((mask>>chocolate)&1)==0){
				dp[mask]+=dp[mask|(1<<chocolate)];
			}
		}
	}
	return dp[0];
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<vector<int>> arr(n,vector<int>(n,0));
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	cout<<AllocateChocolate(arr);
	return 0;
}