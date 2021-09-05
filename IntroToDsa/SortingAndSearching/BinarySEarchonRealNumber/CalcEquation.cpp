//x^2+sqrt(x)=c;
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
float calc(float c){
    float lo = 1.0f,hi = 1e10f;
    float mid=0.0;
    for(int i=1;i<150;i++){
         mid=float(lo+(hi-lo)/float(2));
        if(mid*mid+sqrt(mid)==c){
            return mid;
        }
    else if(mid*mid+sqrt(mid)>c){
        hi=mid;
    }
    else{
        lo=mid;
    }
    }
    return mid;
}
int main(int argc, char const *argv[])
{
    float c=15.6;
    float ans=calc(c);
    cout<<std::setprecision(5)<<ans;
    return 0;
}
