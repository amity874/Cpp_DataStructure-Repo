#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
void PrintSubset(std::vector<int>&arr1,std::vector<int>&arr,int n,int i){
    if(i==n){
        if(arr.size()>0){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i];
        }
        }
        return;
    }
        arr.push_back(arr1[i]);
        PrintSubset(arr1,arr,n,i+1);
        arr.push_back(arr1[  ;
        PrintSubset(arr1,arr,n,i+1);

}
int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int>a;
    std::vector<int>arr={1,2,3};
    PrintSubset(arr,a,arr.size(),0);
    return 0;
}
