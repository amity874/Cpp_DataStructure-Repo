#include<bits/stdc++.h>
bool isItsafe(std::vector<std::vector<int>>&visited,int i,int j,int n){
    return (i>=0 && j>=0 && i<=n-1 && j<=n-1 &&visited[i][j]==false);
}
int totalpath=0;
void Helper(std::vector<std::vector<int>>&grid,std::vector<std::vector<int>>&visited,int i,int j,int n){
    if(i==n-1 && j==n-1){
        totalpath++;
        return;
    }
    if(not isItsafe(visited,i,j,n)){
        return;
    }
    visited[i][j]=true;
        if(i+1<=n-1 && grid[i+1][j]==0){
            Helper(grid,visited,i+1,j,n);
        }
        if(j+1<=n-1 && grid[i][j+1]==0){
            Helper(grid,visited,i,j+1,n);
        }
        if(i-1>=0 && grid[i-1][j]==0){
            Helper(grid,visited,i-1,j,n);
        }
        if(j-1>=0 && grid[i][j-1]==0){
            Helper(grid,visited,i,j-1,n);
        }
    visited[i][j]=false;
}
int PlaceQueen(std::vector<std::vector<int>>&grid,int n){
    std::vector<std::vector<int>>visited(n,std::vector<int>(n,0));
    Helper(grid,visited,0,0,n);
    return totalpath;
}
int main(int argc, char const *argv[]){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>>grid(n,std::vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>grid[i][j];
        }
    }
    std::cout<<PlaceQueen(grid,n);
    return 0;
}
