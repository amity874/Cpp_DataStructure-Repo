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
struct Flowers {
	ll h;
	ll b;
};
ll flowers(vector<Flowers>&a, int n) {
	vi dp(n + 1);
	map<ll, ll>SortedFlowers;
	dp[1] = a[1].b;
	SortedFlowers[a[1].h] = a[1].b;
	ll ans = dp[1];
	loop(i, 2, n) {
		dp[i] = a[i].b;
		auto it = SortedFlowers.lower_bound(a[i].h + 1);
		if (it != SortedFlowers.begin()) {
			it--;
			dp[i] += it->second;
		}
		SortedFlowers[a[i].h] = dp[i];
		it = SortedFlowers.upper_bound(a[i].h);
		while (it != SortedFlowers.end() and it->second <= dp[i]) {
			auto temp = it;
			temp++;
			SortedFlowers.erase(it);
			it = temp;
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}
int Findmin(vi &arr, int i) {
	int min = i;
	while (i < arr.size()) {
		if (arr[i] < arr[min]) {
			min = i;
		}

		i++;
	}
	return min;
}
void Selection_sort(vi &arr) {
	loop(i, 0, arr.size() - 1) {
		int min_idx = Findmin(arr, i);
		if (i != min_idx) {
			swap(arr[i], arr[min_idx]);
		}
	}
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin >> n;
	vi arr;
	while (n--) {
		int x;
		cin >> x;
		arr.pb(x);
	}
	Selection_sort(arr);
	logarr(arr, 0, arr.size() - 1);
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
