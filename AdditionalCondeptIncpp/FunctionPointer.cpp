#include<bits/stdc++.h>
char f(int n,char ch){
    std::cout<<"hey\n";
    return ch;
}
int sq(int x){
    return x*x;
}
int cube(int x){
    return x*x*x;
}
int gun(int x,int (*fun)(int)){
    return fun(x);
}
int main(int argc, char const *argv[])
{
    char (*p)(int,char)=f;
    std::cout<<p(10,'k')<<'\n';
    std::cout<<gun(10,cube)<<"\n";
    return 0;
}
