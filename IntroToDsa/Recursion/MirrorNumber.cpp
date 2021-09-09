#include<bits/stdc++.h>
using namespace std;
std::vector<string> CalcMirrorNumber(int n,int m){
    if(n==0){
        return {""};
    }
    if(n==1){
        return {"0","1","8"};
    }
    std::vector<string> temp=CalcMirrorNumber(n-2,m);
    std::vector<string>result;
    for(string s:temp){
        if(n!=m){
            result.push_back("0"+s+"0");
        }
        result.push_back("1"+s+"1");
        result.push_back("6"+s+"9");
        result.push_back("8"+s+"8");
        result.push_back("9"+s+"6");
    }
    return result;
}
int main(int argc, char const *argv[])
{
   
    std::vector<string> ans=CalcMirrorNumber(4,4);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
