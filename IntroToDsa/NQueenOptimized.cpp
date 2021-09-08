#include<bits/stdc++.h>
using namespace std;
std::bitset<100> col,leftDiagonal,rightDiagonal;
int ans=0;
void countQueenPath(int n,int cr){
    if(cr==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!col[i]&&!leftDiagonal[(cr-i)+(n-1)]&& !rightDiagonal[(cr+i)]){
            col[i]= leftDiagonal[(cr-i)+(n-1)]=rightDiagonal[(cr+i)]=1;
            countQueenPath(n,cr+1);
            col[i]= leftDiagonal[(cr-i)+(n-1)]= rightDiagonal[(cr+i)]=0;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    countQueenPath(n,0);
    cout<<ans;
    return 0;
}
