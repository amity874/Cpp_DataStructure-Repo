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
class Product { // this is a blue print
	string name; // data members
	int cost;
	int discount;

	// own constructor

public:
	Product() {} // default constrcutor

	Product(string n, int c) {
		name = n;
		cost = c;
	}

	Product(string name, int c, int d) {
		this->name = name;
		this->cost = c;
		discount = d;
	}

	void display() {
		cout<<name<<" "<<cost<<" "<<discount<<endl;
	}

	void setCost(int c) { // setter
		if(c < 0) return;
		cost = c;
	}

	int getCost() { // getter
		return cost;
	}

};

int main(int argc, char const *argv[])
{
	file_i_o();
	Product shirt;//this much call default constructor
	Product iphone("Iphone",89090,89);
	iphone.setCost(7);
	cout<<sizeof(iphone)<<" "<<sizeof(shirt)<<endl;
	Product *p=&iphone;
	cout<<p->getCost()<<endl;//access by pointer
	cout<<(*p).getCost()<<endl;
	return 0;
}
