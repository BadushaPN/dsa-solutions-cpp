#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Merge nums2 into nums1 as one sorted array. nums1 has size m + n,
    // with the first m elements valid and the last n elements set to 0.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // pointer for nums1
        int j = n - 1;          // pointer for nums2
        int k = m + n - 1;      // write pointer for nums1

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    sol.merge(nums1, 3, nums2, 3);
    for (int x : nums1) cout << x << " ";
    cout << endl; // Expected: 1 2 2 3 5 6

    vector<int> a2 = {0};
    vector<int> b2 = {1};
    sol.merge(a2, 0, b2, 1);
    for (int x : a2) cout << x << " ";
    cout << endl; // Expected: 1

    vector<int> a3 = {4,5,6,0,0,0};
    vector<int> b3 = {1,2,3};
    sol.merge(a3, 3, b3, 3);
    for (int x : a3) cout << x << " ";
    cout << endl; // Expected: 1 2 3 4 5 6

    return 0;
}
