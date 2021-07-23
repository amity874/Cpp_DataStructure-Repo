#include<bits/stdc++.h>
// --===Amit pandey--===
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int t;
	cin>>t;
	while(t--){
	pq_max max_heap;
    pq_min min_heap;
    while (true) {
    	int a;
    	cin>>a;

      if (a == 0)
        break;
      else if (a == -1) {
        cout<<max_heap.top()<<endl;
        max_heap.pop ();
        if (max_heap.size() < min_heap.size()) {
          int temp = min_heap.top ();
          min_heap.pop ();
          max_heap.push (temp);
        }
      }
      else {
        if (max_heap.size() == 0 && min_heap.size() == 0)
          max_heap.push (a);
        else {
          int temp = max_heap.top ();
          if (a >= temp)
            min_heap.push (a);
          else
            max_heap.push (a);

          if (max_heap.size() < min_heap.size()) {
            int temp = min_heap.top ();
            min_heap.pop ();
            max_heap.push (temp);
          }
          else if (max_heap.size() > min_heap.size() + 1) {
            int temp = max_heap.top ();
            max_heap.pop ();
            min_heap.push (temp);
          }
        }
    }
  }
	}
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
