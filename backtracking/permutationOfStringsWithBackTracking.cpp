// Permutations of string with backtracking

#include<bits/stdc++.h>
using namespace std;

void permutation(string &original, int i) {
    if (i == original.size() - 1) {
        cout << original << endl;
        return;
    }
    
    unordered_set<char> swapped;
    for (int idx = i; idx < original.size(); idx++) {
        if (swapped.find(original[idx]) != swapped.end()) {
            continue;
        }
        swapped.insert(original[idx]);
        swap(original[i], original[idx]);
        permutation(original, i + 1);
        swap(original[i], original[idx]);
    }
}

int main() {
    string original = "aba";
    permutation(original, 0);
    return 0;
}

