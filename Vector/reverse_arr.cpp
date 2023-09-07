#include<iostream>
#include<vector>

using namespace std;

void display(vector<int>&a)
{
	for(int i = 0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}
	
	return;
}

int main()
{
	int size;
    cout<<"Size of array: ";
    cin>>size;
    
    vector<int>arr1;
    
    cout<<"Enter the elements: "<<endl;
    for(int i = 0; i<size; i++)
    {
    	int q;
    	cin>>q;
    	arr1.push_back(q);
	}
	
	display(arr1);
	
	cout<<endl;
	
	vector<int>arr2;
	
	for(int i = size - 1; i>=0; i--)
	{
		arr2.push_back(arr1[i]);
	}
	
	display(arr2);
	
	cout<<endl;
	return 0;
}
