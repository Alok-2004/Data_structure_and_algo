/*
2182. Construct String With Repeat Limit
You are given a string s and an integer repeatLimit. 
Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. 
You do not have to use all characters from s.
Return the lexicographically largest repeatLimitedString possible.
A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. 
If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> uM;
        for (int i = 0; i < s.size(); i++) {
            uM[s[i]]++;
        }

        priority_queue<pair<char, int>> pq;
        for (auto p : uM) {
            pq.push(p);
        }

        string result = "";

        while (!pq.empty()) {
            auto largest = pq.top();
            pq.pop();
            int len = min(repeatLimit, largest.second);
            for (int i = 0; i < len; i++) {
                result += largest.first;
            }
            if (largest.second - len > 0) {
                if (!pq.empty()) {
                    auto secondLargest = pq.top();
                    pq.pop();
                    result += secondLargest.first;

                    if (secondLargest.second - 1 > 0) {
                        pq.push({secondLargest.first, secondLargest.second - 1});
                    }
                } else {
                    return result;
                }
                pq.push({largest.first, largest.second - len});
            }
        }
        return result;
    }
};


int main(){

}