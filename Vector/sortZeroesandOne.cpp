// M-1 two pass method
/*
#include<iostream>
#include<vector>

using namespace std;

void sort01(vector<int>&v)
{
    int n = v.size();
    int noo = 0;
    int noz = 0;

    for(int i = 0; i<n; i++)
    {
        if(v[i] == 0) noo++;
        else noz++;
    }

    for(int i = 0; i<n; i++)
    {
        if(i<noz)  v[i] = 0;
        else  v[i] = 1;
    }
    return;
}

int main()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;

    sort01(v);

    for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
*/

//M-2 Two ponter method

#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>&v)
{
    int n = v.size(); 
    int i = 0;
    int j = n-1;

    while(i<j)
    {
        if(v[i] == 0) i++;
        if(v[j] == 1) j--;
        if(i>j) break;
        if(v[i] == 1 && v[j] == 0)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

return;
}

void display(vector<int>&v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
return;
}

int main()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    display(v);
    cout<<endl;
    sort(v);
    display(v);

   return 0;    
}