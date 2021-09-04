#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string smallestGoodBase(string n){
    ll num=std::stoll(n);
    for(int i=61;i>2;i--){
        ll lo=2;
        ll hi=num-1;
        while (lo<=hi){
            ll mid=lo+(hi-lo)/2;
            bool flag=0;
            ll val=1,j=1,res=1;
            while (j<i){
                if((val/res)>num){
                    flag=1;
                    break;
                }
                j++;
                val*=mid;
                res+=val;
            }
            if(flag|| res>num){
                hi=mid-1;
            }
            else if(res<num){
                lo=mid+1;
            }
            else return to_string(mid);
        }
    }
    return to_string(num-1);
}
int main(int argc, char const *argv[]){
    cout<<smallestGoodBase("13");
        return 0;
}
