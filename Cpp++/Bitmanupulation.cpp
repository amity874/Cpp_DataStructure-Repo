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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i,j,k,m;
	cin>>i>>j>>k>>m;
	int onmask=(1<<i);
	int offmask=~(1<<j);
	int tmask=(1<<k);
	int cmask=(1<<m);
	cout<<(n|onmask);
	cout<<(n&offmask);
	cout<<(n^tmask);
	cout<<((n&cmask)==0 ? false:true);
	return 0;
}