#include<bits/stdc++.h>
using namespace std;

int minProduct(vector<int> &nums){
    int cn = 0, cz = 0, cp = 0;
    int res = 0;
    int prod_pos = 1;
    int prod_neg = 1;
    int largest_neg = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0) cz++;
        else if( nums[i] < 0){
            cn++;
            prod_neg *= nums[i];
            largest_neg = max( largest_neg, nums[i]);
        }
        else {
            cp++;
            prod_pos *= nums[i];
        }
    }

    if(cn == 0){
        if( cz > 0 ) res = 0;
        else   res = *min_element(nums.begin(), nums.end());
    }else{
        if( cn % 2 == 0){
            res = (prod_neg / largest_neg) * prod_pos;
        }else{
            res = prod_neg * prod_pos;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {1, 2, 3 , 4 , 0 , -1, -2};
    int res = minProduct(nums);
    cout<<res;
}