#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j]) // add '=' make it stable
        {
            res[k++] = a[i++];
        }
        else
        {
            res[k++] = b[j++];
        }
    }

    // Insert remaining elements from a
    while (i < a.size())
    {
        res[k++] = a[i++];
    }

    // Insert remaining elements from b
    while (j < b.size())
    {
        res[k++] = b[j++];
    }
}

void mergeSort(vector<int> &v)
{
    int n = v.size();

    if (n == 1)
        return;

    int n1 = n / 2;
    int n2 = n - n / 2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = v[i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = v[i + n1];
    }
    // recursion
    mergeSort(a);
    mergeSort(b);
    merge(a, b, v);
    a.clear();
    b.clear();

}

int main()
{
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + n); // used to copy a array into a vector
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    mergeSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}

// 1:26:13
