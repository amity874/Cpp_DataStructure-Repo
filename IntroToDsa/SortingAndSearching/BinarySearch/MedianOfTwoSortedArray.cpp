#include<bits/stdc++.h>
using namespace std;
#define inf   1e18
#define ll long long int
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
double getMedian(std::vector<ll>&a1,std::vector<ll>&a2){
  int x=a1.size();
  int y=a2.size();
  if(x>y){
      return getMedian(a2,a1);
  }
  int lo=0;
  int hi=x;
  while (lo<=hi){
      ll partitionX=lo+(hi-lo)/2;
      ll partitionY=(x+y+1)/2-partitionX;
      ll MaxLeftX=0;
      ll MinRightX=0;
      ll MinRightY=0;
      ll MaxLeftY=0;
      if(partitionX==0){
          MaxLeftX=-inf;
      }
      else{
          MaxLeftX=a1[partitionX-1];
      }
      if(partitionY==0){
          MaxLeftY=-inf;
      }
      else{
          MaxLeftY=a2[partitionY-1];
      }
      if(partitionX==x){
          MinRightX=inf;
      }
      else{
          MinRightX=a1[partitionX];
      }
      if(partitionY==y){
          MinRightY=inf;
      }
      else{
          MinRightY=a2[partitionY];
      }
      if(MaxLeftX<=MinRightY && MaxLeftY<=MinRightX){
          if((x+y)%2==0){
              return (double)(std::max(MaxLeftX,MaxLeftY)+min(MinRightX,MinRightY))/2;
          }
          else{
              return (double)(std::max(MaxLeftY,MaxLeftX));
          }
      }
      else if(MaxLeftX>MinRightY){
        //need to go left
        hi=partitionX-1;
      }
      else{
          //need to go right
          lo=partitionX+1;
      }
  }
  return 1.0000;
}
int main(int argc, char const *argv[])
{
    std::vector<ll> a1={1,2};
    std::vector<ll>a2={3,4};
    cout<<getMedian(a1,a2);
    return 0;
}
