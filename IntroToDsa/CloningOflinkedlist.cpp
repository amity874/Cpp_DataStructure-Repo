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
struct Node {
	Node *next, *random;
	int data;
	Node(int data) {
		this->data = data;
		this->next = random = NULL;
	}
};

void Addathead(Node *&head, int data) {
	Node *n = new Node(data);
	n->next = head;
	head = n;
}
int LLsize(Node* &head) {
	int sz = 0;
	while (head != NULL) {
		head = head ->next;
		sz = sz + 1;
	}
	return sz;
}
void insertAtTail(Node *&head, int data) {
	if (head == NULL) {
		head = new Node(data);
		return;
	}
	Node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new Node(data);
	return;
}
void buildList(Node *&head) {
	int data;
	cin >> data;
	while (data != -1) {
		insertAtTail(head, data);
		cin >> data;
	}
}
void Disp(Node *&head) {
	while (head != NULL) {
		cout << head->data << "->" << endl;
		if (head->random != NULL) {
			cout << "Random->" << head->random->data << endl;
		}
		head = head->next;
	}
}
istream& operator >>(istream &is, Node *&head) {
	buildList(head);
	return is;
}
ostream& operator <<(ostream &os, Node *&head) {
	Disp(head);
	return os;
}
Node* CreateClone(Node *head) {
	Node *curr = head, *temp;
	while (curr)
	{
		temp = curr->next;
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}
	curr = head;
	while (curr != NULL) {
		if (curr->next) {
			curr->next->random = curr->random ? curr->random->next : curr->random;
			curr = curr->next ? curr->next->next : curr->next;
		}
	}
	Node *original = head;
	Node *copy = head->next;
	temp = copy;
	while (original && copy) {
		original->next = original->next ? original->next->next : original->next;

		copy->next = copy->next ? copy->next->next : copy->next;
		original = original->next;
		copy = copy->next;
	}
	return temp;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Node *head = NULL;
	cin >> head;
	// head->next->random = head->next;
	// head->random = head->next->random;
	Node *n = CreateClone(head);
	cout << n;
	cout << "Original ll" << endl;
	cout << head;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
