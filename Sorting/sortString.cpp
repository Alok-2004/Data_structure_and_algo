#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s = "ABCJSIBVSCCKD";
    string str = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'I')
        {
            str.push_back(s[i]);
        }
    }

    // Bubble sort
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = str.size() - 1; j > 1; j--)  // Use j > i as the loop condition
        {
            if (str[j] > str[j - 1])
            {
                swap(str[j], str[j - 1]);
            }
        }
    }

    cout << str;

    return 0;
}

