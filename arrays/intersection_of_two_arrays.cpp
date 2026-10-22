#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for (int x : nums1) {
            freq[x]++;
        }

        vector<int> result;
        for (int x : nums2) {
            if (freq[x] > 0) {
                result.push_back(x);
                freq[x]--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res1 = sol.intersect(nums1, nums2);
    for (int x : res1) cout << x << " ";
    cout << endl; // 2 2

    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> res2 = sol.intersect(nums3, nums4);
    for (int x : res2) cout << x << " ";
    cout << endl; // 4 9

    vector<int> nums5 = {1, 2, 3};
    vector<int> nums6 = {4, 5, 6};
    vector<int> res3 = sol.intersect(nums5, nums6);
    for (int x : res3) cout << x << " ";
    cout << endl; // empty

    return 0;
}
