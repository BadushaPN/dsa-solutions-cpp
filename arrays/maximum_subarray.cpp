#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int best = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }

        return best;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums1) << endl; // 6

    vector<int> nums2 = {1};
    cout << sol.maxSubArray(nums2) << endl; // 1

    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << sol.maxSubArray(nums3) << endl; // 23

    vector<int> nums4 = {-1, -2, -3};
    cout << sol.maxSubArray(nums4) << endl; // -1

    return 0;
}
