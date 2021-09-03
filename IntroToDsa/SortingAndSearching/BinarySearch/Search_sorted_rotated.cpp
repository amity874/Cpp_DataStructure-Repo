#include<bits/stdc++.h>
using namespace std;
int search(std::vector<int>&arr,int target){
    int lo=0;
    int hi=arr.size()-1;
    while (lo<=hi){
        /* code */
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[lo]==arr[mid] && arr[hi]==arr[mid]){
            while (lo<=hi&&arr[lo]==arr[mid]&&arr[hi]==arr[mid]){
                lo++;
                hi--;
            }         
        }
        else if(arr[lo]<=arr[mid]){
            //case1;
            if(target>=arr[lo]&& target<=arr[mid]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        else{
            // case2;
            if(target>=arr[mid]&&target<=arr[hi]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return -1;
    
}
int main(int argc, char const *argv[])
{
     std::vector<int>arr={1,0,1,1,1};
    cout<<search(arr,0);
    return 0;
}

