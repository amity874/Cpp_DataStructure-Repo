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
struct Node {
public:
	char data;
	bool terminal;
	unordered_map<char, Node*>childreen;
	Node(char ch) {
		this->data = ch;
		this->terminal = false;
	}
};
struct trie {
public:
	Node *root;
	trie() {
		this->root = new Node('\0');
	}
	void insert(string str) {
		Node *temp = this->root;
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if (temp->childreen.count(ch)) {
				temp = temp->childreen[ch];
			}
			else {
				Node *n = new Node(ch);
				temp->childreen[ch] = n;
				temp = temp->childreen[ch];
			}
		}
		temp->terminal = true;
	}
	void autoComplete(string str) {
		Node *temp = this->root;
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if (temp->childreen.count(ch)) {
				temp = temp->childreen[ch];
			} else {
				return;
			}
		}
		dfs(temp, str, "");
	}
	void dfs(Node *temp, string str, string output) {
		if (temp == NULL) { //Base case
			return;
		}
		if (temp->terminal) {
			cout << str + output << endl;//self work
		}
		for (auto child : temp->childreen) {
			dfs(child.ss, str, output + child.ff);
		}
	}
};
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	trie t;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		t.insert(s);
	}
	t.autoComplete("san");
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
