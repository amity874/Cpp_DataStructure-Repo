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
ll power_of10(int n){
	ll result=1;
	for(int i=1;i<=n;i++){
		result*=10;
	}
	return result;
}
ll Sum_of_digit(ll num){
	// base case
	if(num/10==0){
		return ((num)*(num+1))/2;
	}
	string s=to_string(num);
	int n= s.size();
	ll pow_of1=power_of10(n-1);
	int first=num/pow_of1;
	ll result=0;
	ll sum=power_of10(n-2)*45*(n-1);
	loop(i,0,first-1){
		result=result+(i)*pow_of1+sum;
	}
	int rest_of_the_number=num%pow_of1;
	result+=first*(rest_of_the_number+1);
	result+=Sum_of_digit(rest_of_the_number);
	return result;
}
int main(int argc, char const *argv[])
{
	int a,b;
	while(true){
	cin>>a>>b;
	if(a==-1 and b==-1){
		break;
	}
	ll x=Sum_of_digit(b);
	ll y=Sum_of_digit(a-1);
	cout<<x-y<< endl;
	}
	return 0;
}