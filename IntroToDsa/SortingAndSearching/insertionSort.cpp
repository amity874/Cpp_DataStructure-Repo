#include<bits/stdc++.h>
// --===Amit pandey--===p>
// using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<endl;
using namespace std;
void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
void Sort(std::vector<int>&arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0&&key<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main(int argc, char const *argv[])
{
	std::vector<int>arr={6,4,1,3,6,7};
	Sort(arr);
	logarr(arr,0,10);
	return 0;
}