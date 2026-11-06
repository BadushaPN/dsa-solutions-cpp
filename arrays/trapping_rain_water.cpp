#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                ++left;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                --right;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(height1) << endl; // 6

    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << sol.trap(height2) << endl; // 9

    vector<int> height3 = {1, 2, 3, 4};
    cout << sol.trap(height3) << endl; // 0

    return 0;
}
