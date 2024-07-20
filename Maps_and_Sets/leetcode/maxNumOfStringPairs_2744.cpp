// 31.44

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int maximumNumberOfStringPairs(vector<string>& arr) {
    unordered_set<string> seen;
    int pairs = 0;

    for (auto& str : arr) {
        string reversedStr = str;
        reverse(reversedStr.begin(), reversedStr.end());

        if (seen.find(reversedStr) != seen.end()) {
            pairs++;
            seen.erase(reversedStr);
        } else {
            seen.insert(str);
        }
    }

    return pairs;
}

int main() {
    vector<string> arr = {"abc", "cba", "def", "fed", "ghi"};
    cout << "Maximum Number of String Pairs: " << maximumNumberOfStringPairs(arr) << endl;
    return 0;
}
