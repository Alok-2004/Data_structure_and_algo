#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> freq1, freq2;
        unordered_map<int, int> count1, count2;
        unordered_set<char> set1, set2;

        for (char c : word1) {
            freq1[c]++;
            set1.insert(c);
        }
        for (char c : word2) {
            freq2[c]++;
            set2.insert(c);
        }

        if (set1 != set2) return false;

        for (auto& p : freq1) count1[p.second]++;
        for (auto& p : freq2) count2[p.second]++;

        return count1 == count2;
    }
};
