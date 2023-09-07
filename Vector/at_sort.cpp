#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    
    v.at(3) = 56; //at function for modifing
    cout<<v[3];
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    sort(v.begin(), v.end());// arrange in assecnding order
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;

    return 0;
}

