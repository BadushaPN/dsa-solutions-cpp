#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int minY = INT_MAX;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] < points[i][1]) {
                    if (points[j][1] < minY) {
                        ans++;
                        minY = points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points1 = {{1,1},{2,2},{3,3}};
    cout << "Output: " << sol.numberOfPairs(points1) << endl;  

    vector<vector<int>> points2 = {{6,2},{4,4},{2,6}};
    cout << "Output: " << sol.numberOfPairs(points2) << endl;  

    return 0;
}
