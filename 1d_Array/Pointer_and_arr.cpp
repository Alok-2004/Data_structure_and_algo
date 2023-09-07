#include<iostream>
using namespace std;

int main()
{
	int arr[] = {4,5,6,7,8};
	int *ptr = arr;
	cout<<ptr[3]<<endl; // This will also work
	// arr[i] = i[arr]
	*ptr = 8; // ptr[0] = 8
	ptr++;
	*ptr = 9;
	for(int i = 0; i<=4; i++)
	{
		cout<<*ptr<<"\t";
		ptr++;
	}	
}
