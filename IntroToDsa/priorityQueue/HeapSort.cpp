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
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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

void iterativedownheapify(vector<int>&heap,int idx){
	int lc=(idx*2)+1;
	int rc=(idx*2)+2;
	while(lc<heap.size() and rc<heap.size()){
		 lc=(idx*2)+1;
		 rc=(idx*2)+2;
		int largeidx=idx;
		if(lc<heap.size() and heap[lc]>heap[largeidx]){
			largeidx=lc;
		}
		if(rc<heap.size() and heap[rc]>heap[largeidx]){
			largeidx=rc;
		}
		if(idx==largeidx){
			return;
		}
		swap(heap[idx],heap[largeidx]);
		idx=largeidx;
	}
}
void iterativedownheapify_hs(vector<int>&heap,int idx,int heapsize){
	int lc=(idx*2)+1;
	int rc=(idx*2)+2;
	while(lc<=heapsize and rc<=heapsize){
		 lc=(idx*2)+1;
		 rc=(idx*2)+2;
		int largeidx=idx;
		if(lc<heapsize and heap[lc]>heap[largeidx]){
			largeidx=lc;
		}
		if(rc<heapsize and heap[rc]>heap[largeidx]){
			largeidx=rc;
		}
		if(idx==largeidx){
			return;
		}
		swap(heap[idx],heap[largeidx]);
		idx=largeidx;
	}
}
void buildHeap(vector<int>&heap){
	int i=heap.size()-1;
	i=(i/2)+1;
	while(i>=0){
		iterativedownheapify(heap,i);
		i--;
	}
}
void heapSort(std::vector<int>&heap){
	int n=heap.size();
	buildHeap(heap);
	int i=n-1;
	while(i>=0){
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		n=n-1;
		iterativedownheapify_hs(heap,0,n);
		i-=1;
	}
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	std::vector<int> heap={3,7,-99090,898,90909,78,2,78};
	buildHeap(heap);
	heapSort(heap);
	logarr(heap,0,7);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
