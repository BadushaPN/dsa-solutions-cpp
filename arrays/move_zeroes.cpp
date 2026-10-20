#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }

        while (write < (int)nums.size()) {
            nums[write++] = 0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    for (int x : nums1) cout << x << " ";
    cout << endl; // 1 3 12 0 0

    vector<int> nums2 = {0, 0, 1};
    sol.moveZeroes(nums2);
    for (int x : nums2) cout << x << " ";
    cout << endl; // 1 0 0

    vector<int> nums3 = {1, 2, 3};
    sol.moveZeroes(nums3);
    for (int x : nums3) cout << x << " ";
    cout << endl; // 1 2 3

    return 0;
}
