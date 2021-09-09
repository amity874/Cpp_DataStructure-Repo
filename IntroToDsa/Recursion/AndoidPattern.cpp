#include<bits/stdc++.h>
using namespace std;
std::vector<vector<int>> skip(10,std::vector<int>(10,0));
std::vector<string> res;
int Helper(std::vector<bool>&visited,int currentDigit,int remainingDigit){
    if(remainingDigit==0){
        return 1;
    }
    visited[currentDigit]=true;
    int ans=0;
    for(int i=1;i<=9;i++){
        if(not visited[i] && (skip[currentDigit][i]==0 or visited[skip[currentDigit][i]]==true)){
            ans+=Helper(visited,i,remainingDigit-1);
        }
    }
    visited[currentDigit]=false;
    return ans;
}
int calculatePattern(int n,int m){
 skip[1][7]=skip[7][1]=4;
 skip[3][9]=skip[9][3]=6;
 skip[7][9]=skip[9][7]=8;
 skip[1][3]=skip[3][1]=2;
 skip[1][9]=skip[9][1]=skip[3][7]=skip[7][3]=skip[2][8]=skip[8][2]=skip[4][6]=skip[6][4]=5;
 std::vector<bool> visited(10,false);
 int ans=0;
 for(int i=n;i<=m;i++){
     ans+=Helper(visited,1,i-1)*4;
     ans+=Helper(visited,2,i-1)*4;
     ans+=Helper(visited,5,i-1);
 } 
 return ans;  
}
int  PrintHelper(std::vector<bool>&visited,int currentDigit,int remainingDigit,string str){
    if(remainingDigit==0){
        res.push_back(str);
        return 1;
    }
    visited[currentDigit]=true;
    int ans=0;
    for(int i=1;i<=9;i++){
        if(not visited[i] && (skip[currentDigit][i]==0 or visited[skip[currentDigit][i]]==true)){
            ans+=PrintHelper(visited,i,remainingDigit-1,str+to_string(i));
        }
    }
    visited[currentDigit]=false;
    return ans;
}
int PrintPattern(int n,int m){
 skip[1][7]=skip[7][1]=4;
 skip[3][9]=skip[9][3]=6;
 skip[7][9]=skip[9][7]=8;
 skip[1][3]=skip[3][1]=2;
 skip[1][9]=skip[9][1]=skip[3][7]=skip[7][3]=skip[2][8]=skip[8][2]=skip[4][6]=skip[6][4]=5;
 std::vector<bool> visited(10,false);
 int ans=0;
 for(int i=n;i<=m;i++){
     ans+=PrintHelper(visited,1,i-1,"1");
     ans+=PrintHelper(visited,2,i-1,"2");
     ans+=PrintHelper(visited,3,i-1,"3");
     ans+=PrintHelper(visited,4,i-1,"4");
     ans+=PrintHelper(visited,5,i-1,"5");
     ans+=PrintHelper(visited,6,i-1,"6");
     ans+=PrintHelper(visited,7,i-1,"7");
     ans+=PrintHelper(visited,8,i-1,"8");
     ans+=PrintHelper(visited,9,i-1,"9");
 } 
 return ans;  
}
int main(int argc, char const *argv[])
{
    int n=1;
    int m=2;   
    cout<<PrintPattern(n,m);
    cout<<"\n";

     for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
