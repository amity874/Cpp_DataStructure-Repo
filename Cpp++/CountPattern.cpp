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
vector<vector<ll>>skip(10, vector<ll>(10, 0));
int helper(vector<bool> &visited, int currentDigit, int remainingDigit) {
	if (remainingDigit < 0)return 0;
	if (remainingDigit == 0)return 1;
	visited[currentDigit] = true;
	int result = 0;
	loop(i, 1, 9) {
		if (not visited[i] and (skip[currentDigit][i] == 0 or visited[skip[currentDigit][i]] == true)) {
			result += helper(visited, i, remainingDigit - 1);
		}
	}
	visited[currentDigit] = false;
	return result;
}
int countpattern(int m, int n) {
	skip[1][3] = skip[3][1] = 2;
	skip[1][7] = skip[7][1] = 4;
	skip[3][9] = skip[9][3] = 6;
	skip[7][9] = skip[9][7] = 8;
	skip[4][6] = skip[6][4] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[1][9] = skip[9][1] = 5;
	int result = 0;
	vector<bool>visited(10, false);
	loop(i, m, n) {
		result += helper(visited, 1, i - 1) * 4;
		result += helper(visited, 2, i - 1) * 4;
		result += helper(visited, 5, i - 1);
	}
	return result;
}
int helper(vector<bool> &visited, int currentDigit, int remainingDigit, string output) {
	if (remainingDigit < 0)return 0;
	if (remainingDigit == 0) {
		cout << output << endl;
		return 1;
	}
	visited[currentDigit] = true;
	int result = 0;
	loop(i, 1, 9) {
		if (not visited[i] and (skip[currentDigit][i] == 0 or visited[skip[currentDigit][i]] == true)) {
			result += helper(visited, i, remainingDigit - 1, output + (to_string(i)));
		}
	}
	visited[currentDigit] = false;
	return result;
}
int  printpattern(int m, int n, string output) {
	skip[1][3] = skip[3][1] = 2;
	skip[1][7] = skip[7][1] = 4;
	skip[3][9] = skip[9][3] = 6;
	skip[7][9] = skip[9][7] = 8;
	skip[4][6] = skip[6][4] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[1][9] = skip[9][1] = 5;
	int result = 0;
	vector<bool>visited(10, false);
	loop(i, m, n) {
		result += helper(visited, 1, i - 1, output + "1");
		result += helper(visited, 2, i - 1, output + "2");
		result += helper(visited, 3, i - 1, output + "3");
		result += helper(visited, 4, i - 1, output + "4");
		result += helper(visited, 5, i - 1, output + "5");
		result += helper(visited, 6, i - 1, output + "6");
		result += helper(visited, 7, i - 1, output + "7");
		result += helper(visited, 8, i - 1, output + "8");
		result += helper(visited, 9, i - 1, output + "9");
	}
	return result;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int m, n;
	cin >> m >> n;
	ll k = printpattern(m, n, "");
	cout << "total no of pattern-> " << k << endl;
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}