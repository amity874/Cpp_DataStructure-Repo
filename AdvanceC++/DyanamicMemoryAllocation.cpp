#include<bits/stdc++.h>
using namespace std;
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
int main(int argc, char const *argv[])
{
	file_i_o();
	//lets try to create a bucket of int in heap
	int *ptr=new int(8);
	cout<<(*ptr)<<endl;
	//lets try to make an array in heap
	int *arr=new int[10];
	//fill array with all zeros
	int *arr1=new int[10]();
	int rows=4;
	int cols=4;
	int **grid=new int*[rows];//this will initialize only primary array
	for(int i=0;i<rows;i++){
		grid[i]=new int[rows]();//primary array points to secondary array thats how we point one array to secondary array
		grid[i]=new int[cols]();//^
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}
	// int *p;//this will create very big pool of memory which is not handle by normal machine
	// for(int i=0;i<1000000;i++){
	// 	p=new int[1000000];
	// }
	/*
	one solution of above roblem is we can use nothrow 
	which cn hanle this situation
	*/
	// int *r = new int(nothrow)(10);
	// if(!r){
	// 	cout<<"Memory not allocated"<<endl;
	// 	return 0;
	// }
	return 0;
}
