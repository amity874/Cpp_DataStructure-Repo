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
//this will handle only +ve element
// void CountingSort(vector<int> &arr) {
// 	int max = *max_element(all(arr));
// 	vector<int> freq(max + 1, 0);
// 	for (int &el : arr) { //freq map
// 		freq[el]++;
// 	}
// 	for (int i = 1; i <= max; i++) {
// 		freq[i] = freq[i] + freq[i - 1];
// 	}
// 	vector<int>output(arr.size(), 0);
// 	looprev(i, arr.size() - 1, 0) {
// 		output[freq[arr[i]] - 1] = arr[i];
// 		freq[arr[i]]--;ssss
// 	}
// 	arr = output;
// }
//for -ve element
void CountingSort(vector<int> &arr) {
	int max = *max_element(all(arr));
	int min = *min_element(all(arr));
	int range = max - min + 1;
	vector<int>freq(range);
	vector<int>output(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		freq[arr[i] - min]++;
	}
	for (int i = 1; i < freq.size(); i++) {
		freq[i] += freq[i - 1];
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		output[freq[arr[i] - min] - 1] = arr[i];
		freq[arr[i] - min]--;

	}
	arr = output;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin >> n;
	vector<int>arr;
	while (n--) {
		int x;
		cin >> x;
		arr.pb(x);
	}
	CountingSort(arr);
	logarr(arr, 0, arr.size() - 1);
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
