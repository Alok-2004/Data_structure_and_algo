#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int>v(5);// intial size is 5 and each element is 7
	cout<<v.size()<<endl;// now size and capCITY is 5
	cout<<v.capacity()<<endl;
	cout<<v[2];
}

