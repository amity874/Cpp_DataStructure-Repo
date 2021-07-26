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
	Node *next=NULL;
	Node(int data){
		this->data=data;
	}
};
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
Node *populateTreeintPerfactBtree(Node *root){
	Node *newlevel=root;
	while(newlevel!=NULL){
		Node *current=newlevel;
		while(current!=NULL){
			if(current->left){
				current->left->next=current->right;
			}
			if(current->right&&current->next){
				current->right->next=current->next->left;
			}
			current=current->next;
		}
		newlevel=newlevel->left;
	}
	return root;
}
Node *populateBTree(Node *root){
	Node *newlevel=root;
	while(newlevel!=NULL){
		Node* p=NULL;
		Node* child=NULL;
		while(newlevel!=NULL){
			if(newlevel->left){
				if(!p){
					p=newlevel->left;
					child=newlevel->left;
				}
				else{
					child->next=newlevel->left;
					child=child->next;
				}
				if(newlevel->right){
					if(!p){
						p=newlevel->right;
						child=newlevel->right;
					}
					else{
						child->next=newlevel->right;
						child=child->next;
					}
				}
			}
			newlevel=newlevel->next;
		}
		newlevel=child;
	}
	return root;
}

void Disp(Node* root){
	Node *startlevel=root;
	cout<<root->data;
	while(startlevel!=NULL){
		Node *current=startlevel;
		cout<<endl;
		while(current!=NULL){
			if(current->left){
				cout<<current->left->data<<" -> "<<current->right->data<<" -> ";
			}
			if(current->right&&current->next){
				cout<<current->right->data<<" -> "<<current->left->data<<" -> ";
			}
			current=current->next;
		}
	startlevel=startlevel->left;
	}
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Node*n=BuildBTRec();
	Node *res= populateTreeintPerfactBtree;
	Node *res=populateBTree(n);
	// Disp(res);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
