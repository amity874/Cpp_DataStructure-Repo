#include<bits/stdc++.h>
// --===Amit pandey--===
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
	Node *next;
	int data;
	Node(int data) {
		this->next = NULL;
		this->data = data;
	}
};

void Addathead(Node *&head, int data) {
	Node *n = new Node(data);
	n->next = head;
	head = n;
}
void Disp(Node *head) {
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
}
int LLsize(Node *head) {
	int sz = 0;
	while (head != NULL) {
		head = head -> next;
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
void Insert(Node *&head, int data, int pos = 0) {
	if (pos == 0) {
		Addathead(head, data);
		return;
	}
	if (pos >= LLsize(head)) {
		insertAtTail(head, data);
		return;
	}
	Node *temp = head;
	while (pos != 1) {
		temp = temp->next;
		pos -= 1;
	}
	Node *n = new Node(data);
	n->next = temp->next;
	temp->next = n;
	return;
}
Node* findmid(Node *&head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	Node *slow = head;
	Node *fast = head->next;
	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
Node* sameSizeLLSum(Node *&head1, Node *&head2, int* carry) {
	if (head1 == NULL or head2 == NULL) {
		return NULL;
	}
	int sum;
	Node* result = new Node(0);
	result->next = sameSizeLLSum(head1->next, head2->next, carry);
	sum = head1->data + head2->data + *carry;
	*carry = sum / 10;
	result->data = sum % 10;
	return result;
}
void deleteAtHead(Node *&head) {
	if (head == NULL) {
		return;
	}
	Node *temp = head;
	head = head->next;
	delete temp;
	return;
}
void deleteAtTail(Node *&head) {
	Node *temp = head;
	Node *prev = NULL;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
	return;
}
void deleteAt(Node *&head, int pos = 0) {
	if (head == NULL) {
		return;
	}
	if (pos == 0) {
		deleteAtHead(head);
		return;
	}
	if (pos > LLsize(head)) {
		deleteAtTail(head);
		return;
	}
	int jump = 0;
	Node *temp = head;
	Node *prev = NULL;
	while (jump <= pos - 1) {
		prev = temp;
		temp = temp->next;
		jump += 1;
	}
	prev->next = temp->next;
	delete temp;
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
Node* Merge(Node *&lefthf, Node *righthf) {
	if (lefthf == NULL) {
		return righthf;
	}
	if (righthf == NULL) {
		return lefthf;
	}
	Node *c;
	if (lefthf->data < righthf->data) {
		c = lefthf;
		c->next = Merge(lefthf->next, righthf);
	} else {
		c = righthf;
		c->next = Merge(lefthf, righthf->next);
	}
	return c;
}
Node *Mergesort(Node *&head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	Node *mid = findmid(head);
	Node *lefthf = head;
	Node *righthf = mid->next;
	mid->next = NULL;
	lefthf = Mergesort(lefthf);
	righthf = Mergesort(righthf);
	Node *c = Merge(lefthf, righthf);
	return c;
}
istream& operator>>(istream & is, Node *&head) {
	buildList(head);
	return is;
}

ostream& operator<<(ostream & os, Node *&head) {
	Disp(head);
	return os;
}
int main(int argc, char const * argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Node *head1 = NULL;
	// Node *head2 = NULL;
	cin >> head1;
	// cin >> head2;
	// int c = 0;
	// int *carry;
	// carry = &c;
	// Node *result = sameSizeLLSum(head1, head2, carry);
	cout << head1 << endl;
	// cout << head2 << endl
	Node* sort = Mergesort(head1);
	cout << sort << endl;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
