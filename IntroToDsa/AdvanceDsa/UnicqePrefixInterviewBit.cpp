#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;
class Node{	
public:
	int freq=0;
	unordered_map<char,Node*> childreen;
	
};
void insert(Node* root,string str){
	Node *temp=root;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(!temp->childreen.count(ch)){
			temp->childreen[ch]=new Node();
		}
		temp->childreen[ch]->freq++;
		temp=temp->childreen[ch];
	}
}
void printPrefix(Node *root,string output){
	if(root==NULL){
		return;
	}
	if(root->freq==1){
		cout<<output<<endl;
		return;
	}
	for(auto ch:root->childreen){
	printPrefix(ch.second,output+ch.first);
	}
}

void findSortestPrefix(std::vector<string>&words){
	Node *root=new Node();
	for(string s:words){
		insert(root,s);
	}
	printPrefix(root,"");
}
int main(int argc, char const *argv[])
{
	/* code */
	std::vector<string> s={"zebrs","dog","dove","duck"};
	findSortestPrefix(s);
	return 0;
}
