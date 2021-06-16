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
int n;
vi ass(10005,0);
vi cap(10005,0);
ll dp[10005][5005];
ll calc(int i,int c,int a){
	if(dp[i][a]!=-1)return dp[i][a];
	if(i==n){//Base case
		return 0;
	}
	if(a==n/2){
		return dp[i][a]=calc(i+1,c+1,a)+cap[i];
	}
	else if(a==c){
		return dp[i][a]=calc(i+1,c,a+1)+ass[i];
	}
	else{
		return dp[i][a]=min(calc(i+1,c,a+1)+ass[i],calc(i+1,c+1,a)+cap[i]);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	loop(i,0,n-1){
		cin>>cap[i]>>ass[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=ass[0]+calc(1,0,1);
	cout<<dp[0][0];
	return 0;
}