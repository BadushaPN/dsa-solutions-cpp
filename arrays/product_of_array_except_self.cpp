#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // left products
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // right products
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> res1 = sol.productExceptSelf(nums1);
    for (int x : res1) cout << x << " ";
    cout << endl; // 24 12 8 6

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> res2 = sol.productExceptSelf(nums2);
    for (int x : res2) cout << x << " ";
    cout << endl; // 0 0 9 0 0

    vector<int> nums3 = {2, 3, 4};
    vector<int> res3 = sol.productExceptSelf(nums3);
    for (int x : res3) cout << x << " ";
    cout << endl; // 12 8 6

    return 0;
}
