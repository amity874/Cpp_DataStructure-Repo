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
ll Kadane(vi &temp,int &start,int &end){
	int n=temp.size();
	ll Maxsum=INT_MIN;
	ll sum=0;
	end=-1;
	ll tempstart=0;
	for(int i=0;i<n;i++){
		sum+=temp[i];
		if(sum<0){
			sum=0;
			tempstart=i+1;
		}
		else if(sum>Maxsum){
			Maxsum=sum;
			start=tempstart;
			end=i;
		}
	}
	if(end!=-1){
		return Maxsum;
	}
	//to handle negative number
	start=end=0;
	Maxsum=temp[0];
	for(int i=0;i<n;i++){
		if(Maxsum<temp[i]){
			Maxsum=temp[i];
			start=end=i;
		}
	}
	return Maxsum;
}
vi Maxsumrect(vector<vector<ll>> &arr){
	int n=arr.size();
	int m=arr[0].size();
	vi temp(n,0);
	ll result=INT_MIN;
	int start,end,tlc,tlr,brc,brr;
	for(int Leftcol=0;Leftcol<m;Leftcol++){
		temp.assign(n,0);
		for(int Rightcol=Leftcol;Rightcol<m;Rightcol++){
			for(int i=0;i<n;i++){
				temp[i]+=arr[i][Rightcol];
			}
			int sum=Kadane(temp,start,end);
			if(sum>result){
				result=sum;
				tlc=Leftcol;
				brc=Rightcol;
				tlr=start;
				brr=end;
			}
		}
	}
	return {result,tlc,brc,tlr,brr};
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<vector<ll>> arr(n,vector<ll> (m,0));
	loop(i,0,n-1){
		loop(j,0,m-1){
			cin>>arr[i][j];
		}
	}
	vi result=Maxsumrect(arr);
	logarr(result,0,result.size()-1);
	return 0;
}