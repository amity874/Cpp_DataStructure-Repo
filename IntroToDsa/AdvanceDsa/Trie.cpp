#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
public:
	char ch;
	bool isTerminal;
	unordered_map<char,Node*> childreen;
	Node(char ch){
		this->ch=ch;
		this->isTerminal=false;
	}
};
class Trie{
public:
	Node* root;
	Trie(){
		this->root=new Node('\0');
	}
	void insert(string str){
		Node*temp =root;
		for(int i=0;i<str.size();i++){
			char ch=str[i];
			if(temp->childreen.count(ch)){
				temp=temp->childreen[ch];
			}
			else{
				Node *n=new Node(ch);
				temp->childreen[ch]=n;
				temp=n;
			}
		}
	temp->isTerminal=true;
	return;
	}
	bool search(string str){
		Node*temp =root;
		for(int i=0;i<str.size();i++){
			char ch=str[i];
			if(temp->childreen.count(ch)){
				temp=temp->childreen[ch];
			}
			else{
				return false;
			}
		}
		return temp->isTerminal;
	}
	void print_strings_with_prefix(string pre){
		Node *temp=root;
		for(int i=0;i<pre.size();i++){
			char ch=pre[i];
			if(temp->childreen.count(ch)){
				temp=temp->childreen[ch];
			}
			else{
				return;
			}
		}
		dfs(temp,pre,"");
	}
	void dfs(Node* root,string pre,string output){
		if(root==NULL){
			return;
		}
		if(root->isTerminal){
			cout<<pre+output<<endl;
		}
		else{
			for(auto ch:root->childreen){
				dfs(ch.second,pre,output+ch.first);
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	Trie tr;
	while(t--) {
		string s;
		cin>>s;
		tr.insert(s);
	}
	int q;
	cin>>q;
	while(q--) {
		string qs;
		cin>>qs;
		cout<<"String "<<qs<<" is "<<(tr.search(qs) ? "present" : "not present")<<endl;
	}
	string p;
	cout<<"Enter the prefix\n";
	cin>>p;
	tr.print_strings_with_prefix(p);
	
	return 0;
}
