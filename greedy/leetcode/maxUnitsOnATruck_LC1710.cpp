/*
1710. Maximum Units on a Truck
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int number = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (boxTypes[i][0] <= truckSize) {
                number += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                number += truckSize * boxTypes[i][1];
                break;
            }
        }
        return number;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    cout << "Maximum units: " << solution.maximumUnits(boxTypes, truckSize) << endl;
    return 0;
}
