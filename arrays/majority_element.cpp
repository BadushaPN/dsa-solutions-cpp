#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
                count = 1;
            } else if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 3};
    cout << sol.majorityElement(nums1) << endl; // 3

    vector<int> nums2 = {2, 2, 1, 2, 1};
    cout << sol.majorityElement(nums2) << endl; // 2

    vector<int> nums3 = {1};
    cout << sol.majorityElement(nums3) << endl; // 1

    vector<int> nums4 = {1, 2, 3, 4};
    cout << sol.majorityElement(nums4) << endl; // 1 (assumes majority exists)

    return 0;
}
