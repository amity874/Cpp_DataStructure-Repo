#include<bits/stdc++.h>
using namespace std;
void merge(std::vector<int>&a1,int start,int m,int e){
    int i=start;
    int j=m+1;
    int k=0;
    std::vector<int>result((e-start)+1);
    while(i<=m && j<=e){
        if(a1[i]<=a1[j]){
            result[k]=a1[i];
            i++;
        }
        else{
            result[k]=a1[j];
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
    for(int i=start;i<e;i++){
        a1[i]=result[i-start];
    }
}
void inplaceMerge(std::vector<int>&a1,int start,int m,int e){
    int start2=m+1;
    while (start<=m&& start2<=e){
        if(a1[start]<=a1[start2]){
            start++;
        }
        else{
            int temp=a1[start2];
            int idx=start2;
            while (idx!=start){
                /* code */
                a1[idx]=a1[idx-1];
                idx--;
            }
            a1[start]=temp;
            m++;
            start++;
            start2++;
        }
    }
     
}
void MergeSort(std::vector<int>&a,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        // merge(a,start,mid,end);
        inplaceMerge(a,start,mid,end);
    }
}
void mergersorthelper(std::vector<int>&arr){
    MergeSort(arr,0,arr.size()-1);
}
int main(int argc, char const *argv[]){
    std::vector<int>arr={1,2,6,8,1,5,7,8,10,12,13,13,19,22};
    mergersorthelper(arr);
    for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
    }
    return 0;
}

