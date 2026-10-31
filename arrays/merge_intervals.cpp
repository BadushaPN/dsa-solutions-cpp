#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res1 = sol.merge(intervals1);
    for (auto &v : res1) {
        cout << v[0] << " " << v[1] << " | ";
    }
    cout << endl; // 1 6 | 8 10 | 15 18 |

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> res2 = sol.merge(intervals2);
    for (auto &v : res2) {
        cout << v[0] << " " << v[1] << " | ";
    }
    cout << endl; // 1 5 |

    return 0;
}
