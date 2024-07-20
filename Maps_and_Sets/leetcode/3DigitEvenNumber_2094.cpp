#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for (auto ele : arr) m[ele]++;
        
        for (int i = 100; i <= 999; i += 2) {
            int x = i;
            int a = x % 10; x /= 10;
            int b = x % 10; x /= 10;
            int c = x;

            unordered_map<int, int> temp = m;
            
            if (temp[a]-- > 0 && temp[b]-- > 0 && temp[c]-- > 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 0};
    vector<int> result = solution.findEvenNumbers(arr);

    for (int num : result) {
        printf("%d ", num);
    }
    return 0;
}
