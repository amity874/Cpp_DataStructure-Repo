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
void file_i_o()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
int find_minidx(std::vector<int>&arr,int start,int end){
	int min_idx=start;
	start+=1;
	while(start<end){
		if(arr[start]<arr[min_idx]){
			min_idx=start;
		}
			start+=1;
	}
	return min_idx;
}
void SortArray(std::vector<int>&arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		int min_idx=find_minidx(arr,i,n);
		if(i!=min_idx){
			std::swap(arr[i],arr[min_idx]);
		}
	}
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	std::vector<int> arr={5,1,3,7,2,67,90};
	SortArray(arr);
	logarr(arr,0,10);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
