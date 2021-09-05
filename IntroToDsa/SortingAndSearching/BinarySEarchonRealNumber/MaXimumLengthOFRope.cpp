#include<bits/stdc++.h>
#define ll long long int
bool possible(std::vector<int>&arr,float mid,int k){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=int(arr[i]/mid);
    }
    return sum>=k;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={802,743,457,678};
    int k=11;
    float lo=1.0f,hi=1e10f;
    float ans=0.0;
    for(int i=0;i<150;i++){
        float mid=float(lo+(hi-lo)/float(2));
        if(possible(arr,mid,k)){
            lo=mid;
            ans=mid;
        }
        else{
            hi=mid;
        }
    }
    std::cout<<std::setprecision(5)<<ans;
    return 0;
}
