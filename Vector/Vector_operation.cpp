#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	
	v.push_back(6);
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);// way of taking input manually
	v.push_back(2);
	for(int i = 0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	//v.size();
	v.pop_back();// will remove last element will change the siz but nit the capacity
	for(int i = 0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}	
}
