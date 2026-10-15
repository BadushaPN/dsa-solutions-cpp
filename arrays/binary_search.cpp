#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Iterative binary search. Returns index of target or -1 if not found.
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    // Recursive binary search helper
    int searchRecursive(vector<int>& nums, int target) {
        return bs(nums, 0, (int)nums.size() - 1, target);
    }

private:
    int bs(const vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return bs(nums, mid + 1, r, target);
        return bs(nums, l, mid - 1, target);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1,0,3,5,9,12};
    cout << "Iterative: target 9 -> " << sol.search(nums1, 9) << " (expected 4)" << endl;
    cout << "Iterative: target 2 -> " << sol.search(nums1, 2) << " (expected -1)" << endl;

    cout << "Recursive: target 3 -> " << sol.searchRecursive(nums1, 3) << " (expected 2)" << endl;
    cout << "Recursive: target -2 -> " << sol.searchRecursive(nums1, -2) << " (expected -1)" << endl;

    // edge cases
    vector<int> empty;
    cout << "Empty array -> " << sol.search(empty, 5) << " (expected -1)" << endl;

    vector<int> single = {5};
    cout << "Single element (found) -> " << sol.search(single, 5) << " (expected 0)" << endl;
    cout << "Single element (not found) -> " << sol.search(single, 3) << " (expected -1)" << endl;

    return 0;
}
