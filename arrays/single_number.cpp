#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 2, 1};
    cout << sol.singleNumber(nums1) << endl; // 1

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << sol.singleNumber(nums2) << endl; // 4

    vector<int> nums3 = {1};
    cout << sol.singleNumber(nums3) << endl; // 1

    return 0;
}
