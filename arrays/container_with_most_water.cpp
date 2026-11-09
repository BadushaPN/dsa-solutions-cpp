#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentArea = width * min(height[left], height[right]);
            maxWater = max(maxWater, currentArea);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution sol;

    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(heights1) << endl; // 49

    vector<int> heights2 = {1, 1};
    cout << sol.maxArea(heights2) << endl; // 1

    vector<int> heights3 = {4, 3, 2, 1, 4};
    cout << sol.maxArea(heights3) << endl; // 16

    return 0;
}
