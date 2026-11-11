#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;

        k %= static_cast<int>(nums.size());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    sol.rotate(nums1, 3);
    for (int value : nums1) cout << value << ' ';
    cout << endl; // 5 6 7 1 2 3 4

    vector<int> nums2 = {-1, -100, 3, 99};
    sol.rotate(nums2, 2);
    for (int value : nums2) cout << value << ' ';
    cout << endl; // 3 99 -1 -100

    vector<int> nums3 = {1, 2};
    sol.rotate(nums3, 0);
    for (int value : nums3) cout << value << ' ';
    cout << endl; // 1 2

    return 0;
}
