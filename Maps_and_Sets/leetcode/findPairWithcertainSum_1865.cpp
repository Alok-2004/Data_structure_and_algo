#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class FindSumPairs {
public:
    unordered_map<int,int> mp1,mp2;
    vector<int> v1,v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for(auto it : nums1) mp1[it]++;
        for(auto it : nums2) mp2[it]++;
    }
    
    void add(int index, int val) {
        mp2[v2[index]]--;
        v2[index]+=val;
        mp2[v2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto it : mp1){
            if(mp2.find(tot-it.first)!=mp2.end()) 
                cnt+=it.second*mp2[tot-it.first];
        }
        return cnt;
    }
};
