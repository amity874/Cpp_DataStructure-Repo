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
		ll max_xor=(1<<13)-1;
		vector<bool>Isprime(max_xor+5,true);
		Isprime[0]=false;
		Isprime[1]=false;
		loop(i,2,max_xor){
			if(Isprime[i]){
				int j=i*2;
				while(j<=max_xor){
					Isprime[j]=false;
					j+=i; 
				}
			}
		}
		int q;
		cin>>q;
		while(q--){
			int n;
			cin>>n;
			vector<ll>Freq(4505,0);
			vector<vector<ll> >dp(2,vector<ll>(max_xor+5,0));
			loop(i,0,n-1){
				int x;
				cin>>x;
				Freq[x]++;
			}
			dp[0][0]=1;
			int flag=1;
			loop(i,3500,4500){
				loop(j,0,max_xor){
					if(Freq[i]==0){
						dp[flag][j]=dp[1-flag][j];
					}
					else{
						dp[flag][j]=(dp[1-flag][j]*(Freq[i]/2+1)%mod+dp[1-flag][j^i]*((Freq[i]+1)/2)%mod)%mod;
					}
				}
				flag=1-flag;
			}
			ll ans=0;
			loop(i,0,max_xor){
				if(Isprime[i]){
					ans=(ans+dp[1-flag][i])%mod;
				}
			}
			cout<<ans<<endl;

		}
		return 0;
	}
