#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>


using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        unordered_set<int>st;

        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        for(auto i : mp){
            st.insert(i.second);
        }
        if(st.size() != mp.size()) return false;
        return true;

    }
};