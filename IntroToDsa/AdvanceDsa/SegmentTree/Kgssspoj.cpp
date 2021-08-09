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
struct Node{
	ll max1,second_max;
	Node(){
		max1=second_max=0;
	}
};
Node c;
Node zero;
ll arr[100005];
Node segtree[400005];
void build(ll s,ll e,ll tidx){
	if(s==e){
		segtree[tidx].max1=arr[s];
		segtree[tidx].second_max=0;
		return;
	}
	   	ll m=mid(s,e);
	build(s,m,2*tidx);
	build(m+1,e,2*tidx+1);
	segtree[tidx].max1=max(segtree[2*tidx].max1,segtree[2*tidx+1].max1);
	segtree[tidx].second_max=min(max(segtree[2*tidx].max1,segtree[2*tidx+1].second_max),max(segtree[2*tidx].second_max,segtree[2*tidx+1].max1));
}
void update(ll s,ll e,ll i,ll x,ll tidx){
	if(s==e){
		arr[i]=x;
		segtree[tidx].max1=x;
		// segtree[tidx].second_max=0;
		return;
	}
	ll m=mid(s,e);
	if(i>m){
		update(m+1,e,i,x,2*tidx+1);
	}
	else{
		update(s,m,i,x,2*tidx);
	}
	    ll mnn=min(segtree[2*tidx].max1,segtree[2*tidx+1].max1);
    segtree[tidx].max1=max(segtree[2*tidx].max1,segtree[2*tidx+1].max1);
    segtree[tidx].second_max=max(mnn,max(segtree[2*tidx].second_max,segtree[2*tidx+1].second_max));
    if(segtree[tidx].second_max==0)
        segtree[tidx].second_max=mnn;
}
Node query(ll s,ll e,ll left,ll right,ll tidx){
	if(s>right or e<left){
		return zero;
	}
	if(s>=left && e<=right){
		return segtree[tidx];
	}
		ll m1=mid(s,e);
	Node a=query(s,m1,left,right,2*tidx);
	Node b=query(m1+1,e,left,right,2*tidx+1);
    ll mnn=min(a.max1,b.max1);
    c.max1=max(a.max1,b.max1);
    c.second_max=max(mnn,max(a.second_max,b.second_max));
	return c;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
		ll n;
	cin>>n;
	loop(i,1,n){
		cin>>arr[i];
	}
	build(1,n,1);
	ll q;
	cin>>q;
	while(q--){
		char type;
		cin>>type;
		ll x,y;
		cin>>x>>y;
		if(type=='U'){
			update(1,n,x,y,1);
		}
		else{
			c=query(1,n,x,y,1);
			cout<<c.max1+c.second_max<<endl;
		}
	}
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
