#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define CHAR_SIZE 26
struct Trie{
    bool isterminal;
    Trie* childreen[26];
    Trie(){
        this->isterminal=false;
        for(int i=0;i<26;i++){
            this->childreen[i]=NULL;
        }
    }
};
void insert(Trie *const node,string const &str){
    Trie *temp=node;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(temp->childreen[ch-'a']==NULL){
            temp->childreen[ch-'a']=new Trie();
        }
        temp=temp->childreen[ch-'a'];
    }
     temp->isterminal=true;
}
bool search(Trie *const node,string const str){
    int n=str.length();
    std::vector<bool> possible(n+1);
    possible[0]=true;
    for(int i=0;i<n;i++){
         if(possible[i]){
             Trie *temp=node;
        for(int j=i;j<n;j++){
   
            if(!temp){
                break;
            }
             temp=temp->childreen[str[j]-'a'];
             if(temp&& temp->isterminal){
                 possible[j+1]=true;
             }
        }
    }
    }
    return possible[n];
}
bool helper(std::vector<string>&  str,string const &s){
    Trie* node=new Trie();
    for(string &st:str){
        insert(node,st);
    }
    return search(node,s);
}
void freeTrie(Trie *node){
    if(node=NULL){
        return;
    }
    for(int i=0;i<26;i++){
        freeTrie(node->childreen[i]);
    }
    delete(node);
}
int main()
{
    vector<string> dict ={"bat","man","iron"};
 
    // create a Trie to store the dictionary
    Trie* trie = new Trie();
    string str="ironman";
    cout<<helper(dict,str);
    return 0;
}