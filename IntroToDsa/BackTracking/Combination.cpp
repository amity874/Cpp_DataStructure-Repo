#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
// https://leetcode.com/problems/combinations/
void Calulatepermuation(std::vector<int>&temp,int n,int k,int i){
    if(temp.size()==k){
            for(int i=0;i<temp.size();i++){
                cout<<temp[i];
        }
        cout<<"\n";
        return;
    }
    if(i>n){
        return;
    }
    temp.push_back(i);
    Calulatepermuation(temp,n,k,i+1);
    temp.pop_back();
    Calulatepermuation(temp,n,k,i+1);
}
int main(int argc, char const *argv[])
{
    std::vector<int>temp;
    Calulatepermuation(temp,4,2,1);
    return 0;
}
