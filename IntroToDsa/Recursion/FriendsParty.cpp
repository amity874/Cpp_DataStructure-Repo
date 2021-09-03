#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
int Ways(int n){
    if(n==1 or n==2){
        return n;
    }
    int friends=Ways(n-1)+(n-1)*Ways(n-2);
    return friends;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<Ways(n);
    return 0;
}
