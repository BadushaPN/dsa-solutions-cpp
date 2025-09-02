#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
               int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                auto A = points[i];
                auto B = points[j];

                if (A[0] < B[0] && A[1] < B[1]) {
                    bool valid = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        auto C = points[k];

                        if (A[0] <= C[0] && C[0] <= B[0] &&
                            A[1] <= C[1] && C[1] <= B[1]) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) count++;
                }
            }
        }
        return count;
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
