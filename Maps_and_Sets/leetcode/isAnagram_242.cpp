#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

// brute force
// TC = nlogn
/*
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        bool flag = false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) flag = true;

        return flag;    
    }
};
*/

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())  return false;
        unordered_map<char, int> m;
        for(int i = 0; i<s.size(); i++){
            m[s[i]]++;
        }

        for(auto x : t){
            if(m.find(x) != m.end()){
                if(m[x] == 1) m.erase(x);
                else m[x]--;
            }
        }
        
        /*
        for(pair<char, int>x : t){
            if(m.find(x.first) != m.end()){
                if(x.second == 1) m.erase(t[x.first]);
                else x.second--;
            }
        }
        */

        if(m.size() > 0) return false;
        else return    
    }
};