#include<bits/stdc++.h>
// --===Amit pandey--===
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
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
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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
void kclosest(std::vector<vector<int>>&Points,int k){
	std::priority_queue<pair<int,pair<int,int>>>pq;
	for(auto points:Points){//loop through all points
		int x=points[0];
		int y=points[1];
		int dist=x*x+y*y;
		if(pq.size()<k){
			pq.push({dist, {x, y}}); 
		}
		else{
			//we have already k element need to pop
			if(pq.top().ff>dist){
				pq.pop();
				pq.push({dist,{x,y}});
			}
		}
	}
	while(!pq.empty()){
		cout<<pq.top().ff<<"  "<<pq.top().ss.ff<<"  "<<pq.top().ss.ss<<endl;
		pq.pop();
	}
}
void kclosestfromuserpoint(std::vector<vector<int>>&Points,std::pair<int,int>&p,int k){
	std::priority_queue<pair<int,pair<int,int>>> pq;
	for(auto points:Points){
		int x1=points[0];
		int x2=points[1];
		int u1=p.ff;
		int u2=p.ss;
		int dist=sqrt(pow((x1-u1),2)+pow((x2-u2),2));
		if(pq.size()<k){
			pq.push({dist,{x1,x2}});
		}
		else{
			if(pq.top().ff>dist){
				pq.pop();
				pq.push({dist,{x1,x2}});
			}
		}
	}
	while(not pq.empty()){
		cout<<pq.top().ff<<"  "<<pq.top().ss.ff<<"  "<<pq.top().ss.ss<<endl;
		pq.pop();
	}
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	std::vector<vector<int>> Point={{1,0},{2,1},{3,6},{-5,2},{1,-4}};
	std::pair<int,int> p1={2,3};
	kclosestfromuserpoint(Point,p1,3);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
