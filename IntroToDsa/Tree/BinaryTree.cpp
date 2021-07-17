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
int calctilt(Node *root,int *tilt){
	if(root==NULL){
		return 0;
	}
	int leftsum=calctilt(root->left,tilt);
	int rightsum=calctilt(root->right,tilt);
	*tilt+=abs(leftsum-rightsum);
	return leftsum+rightsum+root->data;
}
int returntilt(Node* root){
	int tilt=0;
	calctilt(root,&tilt);
	return tilt;
}
void LevelorderLevelWise(Node*root){
	if(root==NULL){
		return;
	}
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
	Node* front=q.front();
	if(front==NULL){
		cout<<endl;
		q.pop();
		if(!q.empty()){
			q.push(NULL);
		}
	}
	else{
		cout<<front->data<<" ";
		q.pop();
		if(front->left){
			q.push(front->left);
		}
		if(front->right){
			q.push(front->right);
		}
	}		
	}		
}
void Levelorder(Node* root){
	if(root==NULL){
		return;
	}
	else{
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			Node* front=q.front();
			cout<<front->data<<" ";
			q.pop();
			if(front->left){
				q.push(front->left);
			}
			if(front->right){
				q.push(front->right);
			}
		}
	}
}
void elementatMaxdepth(Node* root){
	queue<Node*>q1;
	queue<Node*>q2;
	q1.push(root);
	q1.push(NULL);
	q2.push(root);
	while(!q1.empty()){
		Node* front=q1.front();
		if(front==NULL){
			q1.pop();
			if(!q1.empty()){
				while(!q2.empty()){
					q2.pop();
				}
				q1.push(NULL);
			}
		}
		else{
			q2.push(front);
			q1.pop();
			if(front->left){
				q1.push(front->left);
			}
			if(front->right){
				q1.push(front->right);
			}
		}
	}
	while(!q2.empty()){
		Node *front=q2.front();
		cout<<front->data<<" ";
		q2.pop();
	}
}
void StroreInorderinarray(Node *root,auto &set){
	if(root==NULL){
		return;
	}
	StroreInorderinarray(root->left,set);
	set.insert(root->data);
	StroreInorderinarray(root->right,set);
}
void BuildBst(Node *root,auto &it){
	if(root==NULL){
		return;
	}
	BuildBst(root->left,it);
	root->data=*it;
	it++;
	BuildBst(root->right,it);
}
void topviewrecursive(Node *&root,int dist,std::unordered_map<int,int>&mp){
	if(root==NULL){
		return;
	}
	if(mp[dist]==NULL){
	mp[dist]=root->data;
}
	topviewrecursive(root->left,dist-1,mp);
	topviewrecursive(root->right,dist+1,mp);
}
void topviewrecursiveHelper(Node *root){
	unordered_map<int,int> mp;
	topviewrecursive(root,0,mp);
	for(auto i:mp){
		cout<<i.ss<<" ";
	}
}
void topviewIterative(Node *root){
	queue<pair<Node*,int>>q;
	q.push({root,0});
	std::map<int,int> mp;
	while(!q.empty()){
		Node *temp=q.front().ff;
		int dist=q.front().ss;
		q.pop();
		if(mp.find(dist)==mp.end()){
			cout<<temp->data<<" ";
			mp[dist]=temp->data;
		}
		if(temp->left){
			q.push({temp->left,dist-1});
		}
		if(temp->right){
			q.push({temp->right,dist+1});
		}
	}
}
void ButtomviewHelper(Node *&root,int dist,map<int,int>&mp){
	if(root==NULL){
		return;
	}
	if(mp.count(dist)==NULL or mp.count(dist)>=1){
		mp[dist]=root->data;
	}
	ButtomviewHelper(root->left,dist-1,mp);
	ButtomviewHelper(root->right,dist+1,mp);
}
void Buttomview(Node *root){
	map<int,int> mp;
	ButtomviewHelper(root,0,mp);
	for(auto it:mp){
		cout<<it.ss<<" ";
	}
}
void Buttomviewiterative(Node *&root){
	queue<pair<Node*,int>>q;
	q.push({root,0});
	std::map<int,int> mp;
	while(!q.empty()){
		Node *temp=q.front().ff;
		int dist=q.front().ss;
		q.pop();
		if(mp.count(dist)==NULL or mp.count(dist)>=1){
			cout<<temp->data<<" ";
			mp[dist]=temp->data;
		}
		if(temp->left){
			q.push({temp->left,dist-1});
		}
		if(temp->right){
			q.push({temp->right,dist+1});
		}
	}
}
void VerticalTraverseHelper(Node *&root,int dist,map<int,std::vector<int>> &mp){
	if (root==NULL){
		/* code */
		return;
	}
	if(mp.find(dist)==mp.end() or mp.count(dist)>=1){
		mp[dist].pb(root->data);
	}
	VerticalTraverseHelper(root->left,dist-1,mp);
	VerticalTraverseHelper(root->right,dist+1,mp);
} 
void VerticalTraverse(Node *root){
	map<int,std::vector<int>>mp;
VerticalTraverseHelper(root,0,mp);
map<int,std::vector<int>> ::iterator it;
for(it=mp.begin();it!=mp.end();it++){
	for(int i=0;i<it->second.size();i++){
		cout<<it->second[i]<<" ";
	}
}
}
std::tuple<int,bool> isBalancedhelper(Node *&root,std::tuple<int,bool>&tp){
	if(root==NULL){
		return {-1,true};
	}
	std::tuple<int,bool> leftres=isBalancedhelper(root->left,tp);
	std::tuple<int,bool> rightres=isBalancedhelper(root->right,tp);
	int Bhight=abs(heightofBtree(root->left)-heightofBtree(root->right));
	bool isbalance=(Bhight<=1);
	return {Bhight,isbalance};
}
bool isBalanced(Node *&root){
	std::tuple<int,bool> tp;
	auto res=isBalancedhelper(root,tp);
	return std::get<1>(res);
}
std::tuple<bool,ll,ll>isBsthelper(Node *&root,std::tuple<bool,ll,ll> &tp){
	if(root==NULL){
		return {true,-inf,inf};
	}
	//preorder taverser
	std::tuple<bool,ll,ll> leftres=isBsthelper(root->left,tp);
	std::tuple<bool,ll,ll> rightres=isBsthelper(root->right,tp);
	bool isbst=(std::get<0>(leftres)==true) and (std::get<0>(rightres)==true) and (std::get<1>(leftres)<root->data) and (std::get<2>(rightres)>=root->data);
	ll Max=max(max(root->data,std::get<1>(leftres)),std::get<1>(rightres));
	ll Min=min(min(root->data,std::get<2>(rightres)),std::get<2>(leftres));
	return {isbst,Max,Min};
}
bool isBst(Node *&root){
	std::tuple<bool,ll,ll> tp;
	auto res=isBsthelper(root,tp);
	return get<0>(res);
}
class Pair{
public:
	int height;
	int diameter;
};
Pair DiameterofBt(Node *root,int height,int dia){
	Pair p;
	if(root==NULL){
		return{-1,0};
	}
Pair left=DiameterofBt(root->left,p.height,p.diameter);
Pair right=DiameterofBt(root->right,p.height,p.diameter);
int  h=max(left.height,right.height)+1;
int diameter=max(max(right.diameter,left.diameter),(right.height+left.height)+2);
return {h,diameter};
}
int DiameterHelper(Node *root){
	Pair p1=DiameterofBt(root,-1,0);
	int m=p1.diameter;
	return m;
}

int diameter(Node *root) {
	if(root == NULL) {
		return 0;
	}
	int h1 = heightofBtree(root->left);
	int h2 = heightofBtree(root->right);
	int op1 = h1+h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1, max(op2, op3));
}
void LeftView(Node *root){
	if (root==NULL){
		/* code */
		return;
	}
	cout<<root->data;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
	Node* temp=q.front();
		if(temp==NULL){
			q.pop();
			if(!q.empty()){
			cout<<q.front()->data;
				q.push(NULL);
			}
		}
		else{
			q.pop();
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
void leftviewrecursive(Node *root,int value,int *reference){
	if(root==NULL){
		return;
	}
	if(*reference<value){
		cout<<root->data;
		*reference=value;
	}
	leftviewrecursive(root->left,value+1,reference);
	leftviewrecursive(root->right,value+1,reference);
}
void leftviewrecursivehelper(Node *root){
	int ref=0;
	leftviewrecursive(root,1,&ref);
}
void rightviewrecursive(Node *root,int value,int *ref){
	if(root==NULL){
		return;
	}
	if(*ref<value){
		cout<<root->data;
		*ref=value;
	}
	//reverse preorder
	rightviewrecursive(root->right,value+1,ref);
	rightviewrecursive(root->left,value+1,ref);
}
void rightviewrecursivehelper(Node *root){
	int ref=0;
	rightviewrecursive(root,1,&ref);
}
void RightviewIterative(Node *root){
	if (root==NULL){
		/* code */
		return;
	}
	cout<<root->data;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
	Node* temp=q.front();
		if(temp==NULL){
			q.pop();
			if(!q.empty()){
			cout<<q.front()->data;
				q.push(NULL);
			}
		}
		else{
			q.pop();
			if(temp->right){
				q.push(temp->right);
			}
			if(temp->left){
				q.push(temp->left);
			}
		}
	}
}
Node* buildHelper(std::vector<int>&pre,std::vector<int>&ino,int inlo, int inhi,int *idx,int *total,std::unordered_map<int,int>&mp){
	if(inlo > inhi){
		return NULL;
	}
	Node *nn = new Node(pre[*idx]);
	int s = -1;
	s = mp[pre[*idx]];
	if(s<ino.size()){
		*total+=1;
	}
	if(*total>ino.size()){
		return NULL;
	}
	*idx += 1;
	nn->left = buildHelper(pre, ino, inlo, s-1,idx,total ,mp);
	nn->right = buildHelper(pre, ino, s + 1, inhi,idx,total, mp);
	return nn;
}
Node * buildBTUsingPREIN(std::vector<int>&pre,std::vector<int>&ino){
	std::unordered_map<int,int>mp;
	for(int i=0;i<ino.size();i++){
		mp[ino[i]] = i;
	}
	int idx=0;
	int total=0;
	Node* root = buildHelper(pre, ino, 0, ino.size()-1,&idx,&total,mp);
	return root;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	// Node *n=BuildBTRec();
	// preorder(n);
	// inorder(n);
	// postorder(n);
	// cout<<countNodes(n)<<endl;
	// cout<<heightofBtree(n)<<endl;
	// cout<<returntilt(n);
	// LevelorderLevelWise(n);
	// Levelorder(n);
	// elementatMaxdepth(n);
	// set<int> set;
	// StroreInorderinarray(n,set);
	// auto it=set.begin();
	// BuildBst(n,it);
	// inorder(n);
	// topviewIterative(n);
	// Buttomview(n);
	// VerticalTraverse(n);
	// cout<<DiameterHelper(n);
	// cout<<diameter(n);
	// LeftView(n);
	// leftviewrecursivehelper(n);
	// rightviewrecursivehelper(n);
	// cout<<endl;
	// RightviewIterative(n);
	std::vector<int> ino={4,5,2,3,6,7,1};
	std::vector<int> pre={5,4,6,3,7,2,1};
	Node* root=buildBTUsingPREIN(ino,pre);
	// inorder(root);
	// preorder(root);
	postorder(root);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
