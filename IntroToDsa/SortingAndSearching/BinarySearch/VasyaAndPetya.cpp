#include<bits/stdc++.h>
using namespace std;
bool possible(string &t,string &p,std::vector<int>&arr,int mid){
  string temp= "";
  std:unordered_set<int>s;
  for(int i=0;i<mid;i++){
      s.insert(arr[i]-1);
  }
  for(int i=0;i<t.size();i++){
      if(s.count(i)==0){
          temp+=t[i];
      }
  }
  int i=0;
  int j=0;
  int temp_size=temp.size();
  int p_size=p.size();
  while (i<temp.size()&& j<p_size){
      if(i<temp_size& j<p_size&& temp[i]!=p[j]){
          i++;
      }
      else if(i<temp_size& j<p_size&& temp[i]==p[j]){
          i++;
          j++;
      }
  }
  return j==p_size; 
}
int main(int argc, char const *argv[])
{
    string t="bbbabb";
    string p="bb";
   
    std:vector<int>arr={1,6,3,4,2,5};
    if(p.size()==0){
        cout<<t.size();
    }
    int lo=0;
    int hi=t.size()-p.size();
    int ans=-1;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(t,p,arr,mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
