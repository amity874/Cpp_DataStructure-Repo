#include<bits/stdc++.h>
using namespace std;
int invCount(std::vector<int>&a1,int start,int m,int e){
    int i=start;
    int j=m+1;
    int k=0;
    int count=0;
    std::vector<int>result((a1.size()));
    while(i<=m && j<=e){
        if(a1[i]<=a1[j]){
            result[k]=a1[i];
            i++;
        }
        else{
            result[k]=a1[j];
            count+=(m-i)+1;
            j++;
        }
        k++;
    }
    while (i<=m){
        result[k]=a1[i];
        i++;
        k++;
    }
    while (j<=e){
        result[k]=a1[j];
        j++;
        k++;
    }
    for(int i=start;i<e-1;i++){
        a1[i]=result[i];
    }
    return count;
}
int merge(std::vector<int>&arr,int s,int e){
    int invCnt=0;
    if(s<e){
        int m=(s+e)/2;
        invCnt+=merge(arr,s,m);
        invCnt+= merge(arr,m+1,e);
        invCnt+=invCount(arr,s,m,e);
    }
    return invCnt;
}
int  getinvCount(std::vector<int>&arr){
    return merge(arr,0,arr.size()-1);
}
int main(int argc, char const *argv[])
{
    /* code */
   std::vector<int>a = {1,20,6,4,5};
   cout<<getinvCount(a);
    return 0;
}
