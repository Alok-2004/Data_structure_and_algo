#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;	// you need not to mention size

	v.push_back(6);
	cout<<v.size()<<endl;// Prints size(no. of alements currently stored
	 
	v.push_back(5);
	v.push_back(4);
	cout<<v.capacity()<<endl; //the amount of memory reserved to store elements and double once filled completely
	v.push_back(3);// way of taking input manually
	v.push_back(2);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;
	
	// if you want access/update
	v[0] = 88;
	
	cout<<v[0];// output
}
