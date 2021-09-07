#include<bits/stdc++.h>
using namespace std;
void PrintPermuation(std::vector<int>&arr,std::vector<int>&temp,int i,int n){
    if(i==n){
        if(temp.size()>0){
            for(int i=0;i<temp.size();i++){
                std::cout<<temp[i];
            }
            std::cout<<"\n";
        }
        return;
    }
    temp.push_back(arr[i]);
    PrintPermuation(arr,temp,i+1,n);
    temp.pop_back();
    PrintPermuation(arr,temp,i+1,n);
}
int main(int argc, char const *argv[])
{
    std::vector<int>temp;
    std::vector<int>arr={1,2,3};
    PrintPermuation(arr,temp,0,arr.size());
    return 0;
}
