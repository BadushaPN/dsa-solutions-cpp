#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (!seen.insert(num).second) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << boolalpha << sol.containsDuplicate(nums1) << endl; // true

    vector<int> nums2 = {1, 2, 3, 4};
    cout << boolalpha << sol.containsDuplicate(nums2) << endl; // false

    vector<int> nums3 = {3, 3, 3, 3};
    cout << boolalpha << sol.containsDuplicate(nums3) << endl; // true

    return 0;
}
