#include<iostream>
#include<vector>
#include<climits>
#include<unordered_set>

using namespace std;

int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        if (reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && digit > 7)) return 0;
        if (reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && digit < -8)) return 0;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int countDistinctIntegers(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> s;
    for(int i = 0; i<n; i++){
        int x = reverse(nums[i]);
        s.insert(x);
        s.insert(nums[i]);
    }

    return s.size();
}

int main(){

}