#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>&arr){
        vector<vector<string>> res;
        unordered_map<string, vector<string>>mp;
        for(auto ele : arr){
            string temp = ele;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(ele);
            }

            for(auto ele : mp){
                res.push_back(ele.second);
            }
            return res;
        }        
};

int main(){
    vector<string>arr = {"ate", "eat", "tea", "nat", "bat"};
}