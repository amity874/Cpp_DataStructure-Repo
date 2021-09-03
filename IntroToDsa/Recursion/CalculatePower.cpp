#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
int  pow_(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int temp=pow_(a,b/2);
    if(b%2==0){
        return temp*temp;
    }else{
        return a*temp*temp;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    cout<<pow_(2,3);
    return 0;
}
