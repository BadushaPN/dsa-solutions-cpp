#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutiveSequence(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (set.find(num - 1) == set.end()) {
                int current = 1;
                while (set.find(num + current) != set.end()) {
                    current++;
                }
                longest = max(longest, current);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutiveSequence(nums1) << endl; // 4

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutiveSequence(nums2) << endl; // 9

    vector<int> nums3 = {1, 2, 0, 1};
    cout << sol.longestConsecutiveSequence(nums3) << endl; // 3

    return 0;
}
