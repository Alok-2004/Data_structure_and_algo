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

void reversePart(int i, int j, vector<int>&a)
{
    while(i<j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    return;
}

int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(8);

    display(arr);
    cout<<endl;

    reversePart(0,2,arr);


    display(arr);
    return 0;

}