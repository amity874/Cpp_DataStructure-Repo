#include<bits/stdc++.h>
using namespace std;
void permuatation(std::string s,std::string osf){//for usicque char only
    if(s.size()==0){
        std::cout<<osf<<"\n";
        return;
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        std::string ros=s.substr(0,i)+s.substr(i+1);//ros represent rest of the string
        permuatation(ros,osf+ch);
    }
}
void permuatation2(std::string s,std::string osf){//this can handle repetative char
    if(s.size()==0){
        std::cout<<osf<<"\n";
        return;
    }
    std::unordered_set<char>s1;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(s1.count(ch)==0){     
        s.insert(ch);
        std::string ros=s.substr(0,i)+s.substr(i+1);//ros represent rest of the string
        permuatation(ros,osf+ch);
    }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    permuatation2("ABC","");
    return 0;
}
