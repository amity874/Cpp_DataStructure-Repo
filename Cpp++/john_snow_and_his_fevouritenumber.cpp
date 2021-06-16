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
int main(){
	ll n,k,x;
	cin>>n>>k>>x;
	vi Freq(1500,0);
	vi Temp(1500,0);
	loop(i,0,n-1){
		int ai;
		cin>>ai;
		Freq[ai]++;
	}
	while(k--){
		loop(i,0,1500-1){
			Temp[i]=Freq[i];
		}
		int parity=0;
		loop(i,0,1500-1){
			if(Freq[i]>0){
				int curr=i^x;
				int delta=Freq[i]/2;
				if(parity==0){
					delta+=(Freq[i]&1);
				}
				Temp[i]-=delta;
				Temp[curr]+=delta;
				parity=parity^(Freq[i]&1);
			}
		}
		loop(i,0,1500-1){
			Freq[i]=Temp[i];
		}
	}
	int min_sum=INT_MAX,max_sum=INT_MIN;
	loop(i,0,1500-1){
		if(Freq[i]>0){
			min_sum=min(min_sum,i);
			max_sum=max(max_sum,i);
		}
	}
	cout<<max_sum<<" "<<min_sum;
	return 0;
}