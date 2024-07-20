#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int subArraySum(vector<int>& nums, int k){
        unordered_map<int, int>m;
        int res = 0, s = 0;
        for(auto ele : nums){
            s = s + ele;
            if(s == k) res++;
            if( (m.find(s - k) != m.end())){
                res += m[s - k];
            }
            m[s]++;
        }
        return res;
    }
};

int main(){
    vector<int>nums = {-1,-1,1};
    int k = 0;
    Solution s;
    int res = s.subArraySum(nums, k);
    cout<<res;
}
