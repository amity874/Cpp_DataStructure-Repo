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
Node* findmaxinRst(Node*root){
	while(root->left){
		root=root->left;
	}
	return root;
}
Node * getinosuccessor(Node *root,int key){//iterative version;
	Node *succ=NULL;
	while(1){
		if(key<root->data){
			succ=root;
			root=root->left;
		}
		else if(key>root->data){
			root=root->right;
		}
		else{//we found the desired node
			if(root->left){
				succ=findmaxinRst(root->right);
			}
				break;//node succ will not be in rst 
		}
		if(!root){
			return NULL;
		}
	}
	return succ;
}
void getinosuccessorrecursive(Node *&root,Node *&succ,int key){
	if(root==NULL){
		succ=NULL;
		return;
	}
	if(root->data==key){
		if(root->right){
		succ=findmaxinRst(root->right);
}}
else if(key<root->data){
	succ=root;
	getinosuccessorrecursive(root->left,succ,key);
}
else{
	getinosuccessorrecursive(root->right,succ,key);
}
}
Node* findmininLst(Node*root){
	while(root->left){
		root=root->left;
	}
	return root;
}
Node * getinopredecessor(Node *root,int key){//iterative version;
	Node *succ=NULL;
	while(1){
		if(key<root->data){
		root=root->left;
		succ=root->left;
		}
		else if(key>root->data){
			succ=root;
			root=root->right;
		}
		else{//we found the desired node
			if(root->left){
				succ=succ;
			}
				break;//node succ will not be in rst 
		}
		if(!root){
			return NULL;
		}
	}
	return succ;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Node *root=BuildBTRec();
	// Node *n=getinosuccessor(root,8);
	// cout<<n->data<<endl;
	// Node *succ=NULL;
	// getinosuccessorrecursive(root,succ,8);
	Node* n=getinopredecessor(root,10);
	cout<<n->data;
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
