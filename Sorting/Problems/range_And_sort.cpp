/*
Ques: Given an array, arr[] containing 'n' integers,
 the task is to find an integer (say K) such that after replacing each and every index of the array by |ai - K| 
 where (i = [1, n]), results in a sorted array. 
 If no such integer exists that satisfies the above condition then return -1.
 */
 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

pair<int, int> findRangeOfK(const vector<int>& arr) {
    int n = arr.size();
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());
    
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    int minK = max(abs(sortedArr[0] - minValue), abs(sortedArr[0] - maxValue));
    int maxK = max(abs(sortedArr[n - 1] - minValue), abs(sortedArr[n - 1] - maxValue));
    
    return make_pair(minK, maxK);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    pair<int, int> range = findRangeOfK(arr);
    
    cout << "Range of possible values for K: " << range.first << " to " << range.second << endl;
    
    return 0;
}

