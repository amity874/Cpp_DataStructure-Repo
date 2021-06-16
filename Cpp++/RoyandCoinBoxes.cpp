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
ll start[1000005],end_[1000005],temp[1000005],coins[1000005];
int main(int argc, char const *argv[]){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=1000000;i++){
		start[i]=end_[i]=temp[i]=coins[i]=0;
	}
	while(m--){
		int l,r;
		cin>>l>>r;
		start[l]++;
		end_[r]++;
	}
	temp[1]=start[1];
	for(int i=2;i<=n;i++){
		temp[i]=start[i]-end_[i-1]+temp[i-1];//this will store coins at ith index;
	}
	for(int i=1;i<=n;i++){
	coins[temp[i]]++;	//this will show at the ith index how many boxes have ecactly ith coin	
	}
	// so we need to claculate suffix sum for at least i coin
	for(int j=n-1;j>=0;j--){
		coins[j]=coins[j]+coins[j+1];
	}
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		cout<<coins[x]<<endl;
	}
}