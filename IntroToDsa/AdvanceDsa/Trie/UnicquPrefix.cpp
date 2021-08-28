#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct Trie{
    int freq=0;
    unordered_map<char,Trie*>childreen;
};
void insert(Trie *root,string str){
    Trie* temp=root;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(!temp->childreen.count(ch)){
            temp->childreen[ch]=new Trie();
        }
        temp->childreen[ch]->freq++;
        temp=temp->childreen[ch];
    }
}
void printHelper(Trie *root,string output){
   if(root==NULL){
       return;
   }
   if(root->freq==1){
       cout<<output<<"\n";
       return;
   }
   for(auto ch:root->childreen){
       printHelper(ch.second,output+ch.first);
   }
}
void printprefix(std::vector<string> &str){
    Trie *temp=new Trie();
    for(string &s:str){
        insert(temp,s);
    }
    printHelper(temp,"");
}
int main(int argc, char const *argv[])
{
    /* code */
    std::vector<string> s={"zebrs","dog","dove","duck"};
	printprefix(s);
    return 0;
}
