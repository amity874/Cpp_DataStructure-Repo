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
	ll data=-1;
	Node* left=NULL;
	Node* right=NULL;
	Node(int data){
		this->data=data;
	}
};
std::vector<int>arr;
Node* BuildBTRec(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	Node* root=new Node(d);
	root->left=BuildBTRec();
	root->right=BuildBTRec();
	return root;
}
void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" "<<endl;
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<(root->data)<<" "<<endl;
	inorder(root->right);
}
void postorder(Node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<(root->data)<<" "<<endl;
}
int countNodes(Node* root){
	if(root==NULL){
		return 0;
	}
	int c1=countNodes(root->left);
	int c2=countNodes(root->right);
	return c1+c2+1;
}
int heightofBtree(Node *root){
	if(root==NULL){
		return 0;
	}
	return 1+max(heightofBtree(root->left),heightofBtree(root->right));
}
ll calsize(Node *root){
	if(root==NULL){
		return 0;
	}
	return calsize(root->left)+1+calsize(root->right);
}
ll ans=-inf;
std::tuple<bool,ll,ll,ll>isBsthelper(Node *&root,std::tuple<bool,ll,ll,ll> &tp){
if(root==NULL){
		return {true,1,-inf,inf};
	}
	//preorder taverser
	std::tuple<bool,ll,ll,ll> leftres=isBsthelper(root->left,tp);
	std::tuple<bool,ll,ll,ll> rightres=isBsthelper(root->right,tp);
	bool isbst=(std::get<0>(leftres)==true)and(std::get<0>(rightres)==true) and (std::get<2>(leftres)<root->data) and (std::get<3>(rightres)>=root->data);
	ll Max=max(max(root->data,std::get<2>(leftres)),std::get<2>(rightres));
	ll Min=min(min(root->data,std::get<3>(rightres)),std::get<3>(leftres));
	ll sizeofBst=calsize(root);
	if(isbst){
	if(sizeofBst>ans){
		ans=sizeofBst;
	}
}
	return {isbst,ans,Max,Min};
}
ll mxBst(Node *&root){
	std::tuple<bool,ll,ll,ll> tp;
	auto res=isBsthelper(root,tp);
	return get<1>(res);
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Node *n=BuildBTRec();
	cout<<mxBst(n);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
