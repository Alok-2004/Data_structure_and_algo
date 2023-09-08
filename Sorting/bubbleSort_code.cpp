#include <iostream>
#include <algorithm> // Required for swap function

using namespace std;

void seet(int arr[], int n)
{
    // Sorting odd-indexed elements in descending order
    for (int i = 1; i < n; i += 2)
    {
        for (int j = 1; j < n - i; j += 2)
        {
            if (arr[j] > arr[j + 2])
            {
                swap(arr[j], arr[j + 2]);
            }
        }
    }

    // Sorting even-indexed elements in ascending order
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n - i - 2; j += 2)
        {
            if (arr[j] > arr[j + 2])
            {
                swap(arr[j], arr[j + 2]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    seet(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

