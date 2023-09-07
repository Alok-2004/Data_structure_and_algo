#include<iostream>
using namespace std;
// Its work as pass by reference

void display(int a[],int size)
{
	for(int i = 0; i<=size; i++)
	{
		cout<<a[i]<<"\t";
	}
	return;	
}

void change(int b[],int size)
{
	b[0] = 100;
}
int main()
{
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display(arr, size);
	change(arr, size);
	display(arr, size);
}
