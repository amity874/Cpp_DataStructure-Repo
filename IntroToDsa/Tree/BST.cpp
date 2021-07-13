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
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data=data;
		this->left=NULL;
	this->right=NULL;
	}
};

Node* insertinBST(Node *&root,int d){
	if(root==NULL){
		return new Node(d);
	}
	if(d<root->data){
		root->left=insertinBST(root->left,d);
	}
	else{
		root->right=insertinBST(root->right,d);
	}
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
Node* buildBST(){
	int d;
	cin>>d;
	Node* root=NULL;
	while(d!=-1){
		root=insertinBST(root,d);
		cin>>d;
	}
	return root;
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
bool search(Node *&root,int d){
	if(root==NULL){
		return false;
	}
	if(root->data==d){
		return true;
	}
	if(d<root->data){
		return search(root->left,d);
	}
	else{
		return search(root->right,d);
	}
	return false;
}
Node* DeletefromBST(Node*root,int key){
	if(root==NULL){
		return root;
	}
	else if(root->data<key){
		root->right=DeletefromBST(root->right,key);
	}
	else if(root->data>key){
		root->left=DeletefromBST(root->left,key);
	}
	else{
		if(root->data==key){
			//key has 0 child
			if(root->left==NULL&& root->right==NULL){
				delete(root);
				return NULL;
			}
			//key has only right child
			else if(root->left==NULL&&root->right!=NULL){
				Node *temp=root->right;
				delete(root);
				return temp;
			}
			else if(root->left!=NULL&& root->right==NULL){
				Node* temp=root->left;
				delete(root);
				return temp;
			}
			else{
				Node* nextmax=root->right;
				while(nextmax->left!=NULL){
					nextmax=nextmax->left;
				}
				root->data=nextmax->data;
				root->right=DeletefromBST(root->right,root->data);
				return root;
			}
		}
	}
	return root;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Node *root=buildBST();
	// root=DeletefromBST(root,8);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<"///////"<<endl;
	LevelorderLevelWise(root);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
