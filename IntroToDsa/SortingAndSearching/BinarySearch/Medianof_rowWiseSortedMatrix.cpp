#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int getMedian(int arr[][100],int row,int column){
    int min_ele=INT_MAX;
    int max_ele=INT_MIN;
    for(int i=0;i<row;i++){
        if(arr[i][0]<min_ele){
            min_ele=arr[i][0];///this will find min element in grid
        }
        if(arr[i][column-1]>max_ele){
            max_ele=arr[i][column-1];
        }
    }
    int required=(row*column+1)/2;
    int lo=min_ele;
    int hi=max_ele;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        int partition=0;
        for(int i=0;i<row;i++){
            partition+=std::upper_bound(arr[i],arr[i]+column,mid)-arr[i];//we know row are already sorted so we go row by row
        }
        if(partition<required){
            lo=mid+1;
        }
        else{
            return mid;
        }
    }
    return min_ele;
}
int main(int argc, char const *argv[])
{
  int arr[][100]={{1,3,5},{2,6,9}, {3,6,9}};
  cout<<getMedian(arr,3,3);
    return 0;
}
