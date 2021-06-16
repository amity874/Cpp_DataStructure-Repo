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
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


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
class DllNode
{
public:
	int key;
	int value;
	DllNode* next;
	DllNode* prev;
	DllNode(int key,int value){
		this->key=key;
		this->value=value;
		this->next=NULL;
		this->prev=NULL;
	}
};
int size;
int capacity;
unordered_map<int,DllNode*>cache;
DllNode* head=new DllNode(-1,-1);
DllNode* tail=new DllNode(-1,-1);
void addNodeAtHead(DllNode* node){
	node->prev=head;
	node->next=head->next;
	head->next->prev=node;
	head->next=node;
	return;
}
void removeNode(DllNode* node){
	DllNode* prev=node->prev;
	DllNode* next=node->next;
	prev->next=next;
	next->prev=prev;
}
int removeFromtail(){
	DllNode* temp=tail->prev;
	removeNode(temp);
	return temp->key;
 }
 int moveTohead(DllNode* node){
 	cout<<"Accessed the key"<<node->key<<endl;
 	removeNode(node);
 	addNodeAtHead(node);
 } 
 int get(int k){
 	if(cache.count(k)==0){
 		cout<<"Value is not present in the cache "<<endl;
 		return INT_MIN;
 	}
 	DllNode* node=cache[k];
 	moveTohead(node);
 	return node->value;
 }
int put(int k,int v){
	if(cache.count(k)==0){
		//value is not present
		DllNode* newNode=new DllNode(k,v);
		cache[k]=newNode;
		cout<<"Added a key "<<newNode->key<<endl;
		addNodeAtHead(newNode);
		capacity++;
		if(capacity>size){
			int removekey=removeFromtail();
			cout<<"As the cache is full we need to remove the key "<<removekey<<endl;
			capacity--;
			cache.erase(removekey);
		}
	}
	else{
		//value is already there
		DllNode* temp=cache[k];
		temp->value=v;
		moveTohead(temp);
	}
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	cout<<"Enter the size of the cache"<<endl;
	cin>>size;
	cout<<"size of the cache is "<<size<<endl;
	head->next=tail;
	tail->prev=head;
	int q;
	cin>>q;
	while(q--){
		char ch;
		int k,v;
		cin>>ch;
		if(ch=='p'){
			cin>>k>>v;
			put(k,v);
		}
		else{
			cin>>k;
			int v=get(k);
			cout<<"Value for key "<<k<<" is "<<v<<endl;
		}
	}
	return 0;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
}
