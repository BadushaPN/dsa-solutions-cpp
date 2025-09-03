#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> xs, ys;
        for (auto &p : points) {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        
        vector<pair<int,int>> pts(n);
        for (int i=0; i<n; i++) {
            int cx = lower_bound(xs.begin(), xs.end(), points[i][0]) - xs.begin();
            int cy = lower_bound(ys.begin(), ys.end(), points[i][1]) - ys.begin();
            pts[i] = make_pair(cx, cy);
        }
        int X = xs.size(), Y = ys.size();

        
        vector<vector<int>> grid(X+1, vector<int>(Y+1, 0));
        for (int k=0; k<n; k++) {
            int cx = pts[k].first;
            int cy = pts[k].second;
            grid[cx+1][cy+1]++;
        }

        
        for (int i=1; i<=X; i++) {
            for (int j=1; j<=Y; j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        auto query = [&](int x1, int y1, int x2, int y2) {
            if (x1 > x2 || y1 > y2) return 0;
            return grid[x2][y2] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x1-1][y1-1];
        };

        long long ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                int xa = pts[i].first;
                int ya = pts[i].second;
                int xb = pts[j].first;
                int yb = pts[j].second;

                if (xa <= xb && ya >= yb) {
        
                    int total = query(xa+1, yb+1, xb+1, ya+1);
                    if (total == 2) ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points1 = {{1,1},{2,2},{3,3}};
    cout << "Example 1: " << sol.numberOfPairs(points1) << endl;

    vector<vector<int>> points2 = {{1,3},{3,1},{2,2}};
    cout << "Example 2: " << sol.numberOfPairs(points2) << endl;

    return 0;
}
