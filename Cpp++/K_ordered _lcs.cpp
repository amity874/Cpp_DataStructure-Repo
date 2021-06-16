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
dp[2005][2005][5];
ll KOrdereslcs(vector<int>s1,vector<int>s2,int k,int i,int j){
	if(i==s1.size() or j==s2.size()){
		return 0;
	}
	if(dp[i][j][k]!=-1)return dp[i][j][k];
	ll res=0;
	if(s1[i]==s2[j]){
		res=1+KOrdereslcs(s1,s2,k,i+1,j+1);
	}
	else{
		if(k>0){
			res=1+KOrdereslcs(s1,s2,k-1,i+1,j+1)
		}
		res=max({res,KOrdereslcs(s1,s2,k,i,j+1),KOrdereslcs(s1,s2,k,ki+1,j)});
	}
	return dp[i][j][k]=res;
}
int main(int argc, char const *argv[])
{
	/* code */
	int n,m,k;
	cin>>n>>m>>k;
	loop(i,0,2004){
		loop(j,0,2004){
			dp[i][j]=-1;
		}
	}
	vector<ll>s1(n,0);
	vector<ll>s2(m,0);
	loop(i,0,n){
		cin>>s1[i];
	}
	loop(j,0,m){
		cin>>s2[j];
	}
	cout<<KOrdereslcs(s1,s2,k,0,0);
	return 0;
}