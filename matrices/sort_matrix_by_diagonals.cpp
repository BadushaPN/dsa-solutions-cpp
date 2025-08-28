#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int row = 0; row < n; row++) {
            vector<int> diagonal;
            int i = row, j = 0;

            while (i < n && j < n) {
                diagonal.push_back(grid[i][j]);
                i++; j++;
            }

            sort(diagonal.begin(), diagonal.end(), greater<int>());

            i = row, j = 0;
            for (int k = 0; k < diagonal.size(); k++) {
                grid[i][j] = diagonal[k];
                i++; j++;
            }
        }

        for (int col = 1; col < n; col++) {
            vector<int> diagonal;
            int i = 0, j = col;

            while (i < n && j < n) {
                diagonal.push_back(grid[i][j]);
                i++; j++;
            }

            sort(diagonal.begin(), diagonal.end());

        
            i = 0, j = col;
            for (int k = 0; k < diagonal.size(); k++) {
                grid[i][j] = diagonal[k];
                i++; j++;
            }
        }

        return grid;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};

    auto ans = sol.sortMatrix(grid);

    cout << "Sorted Matrix:" << endl;
    for (auto &row : ans) {
        for (auto &val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
