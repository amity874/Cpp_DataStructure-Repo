#include<bits/stdc++.h>
using namespace std;
void Display(int n,std::vector<std::vector<bool>>&visited){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==true){
                std::cout<<"Q"<<" ";
            }
            else{
                std::cout<<"."<<" ";
            }
        }
        std::cout<<"\n";
    }
}
bool isItSafe(int row,int col,int n,std::vector<std::vector<bool>>&visited){
for(int i=row-1;i>=0;i--){//for checking to column
    if(visited[i][col]==true){
        return false;
    }
}
for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
    if(visited[i][j]==true){
        return false;
    }
}
for(int i=row-1,j=col+1;i>=0&&j<=n-1;i--,j++){
    if(visited[i][j]==true){
        return false;
    }
}
return true;
}
int path=0;
void  NqueenHelper(int current_row,int n,std::vector<std::vector<bool>>&visited){
   if(current_row==n){
       path++;
       Display(n,visited);
       cout<<"\n";
       return;
   }
 for(int i=0;i<n;i++){
    if(isItSafe(current_row,i,n,visited)){
        visited[current_row][i]=true;
        NqueenHelper(current_row+1,n,visited);
        visited[current_row][i]=false;
   }
  }
}
void NqueenGenerator(int n){
    std::vector<std::vector<bool>>visited(n,std::vector<bool>(n,false));
    NqueenHelper(0,n,visited);
}
int main(int argc, char const *argv[])
{
    // int n;
    // std::cin>>n;
    // NqueenGenerator(n);
    // std::cout<<path;
    vector<string> chess(8,string(8,'.'));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
        cout<<chess[i][j]<<" ";
    }
    cout<<"\n";
    }
    return 0;
}
