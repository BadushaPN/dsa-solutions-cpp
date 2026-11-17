#include <bits/stdc++.h>
using namespace std;

// Number of Islands (LeetCode 200)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        const int rows = static_cast<int>(grid.size());
        const int cols = static_cast<int>(grid[0].size());
        const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int islands = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] != '1') continue;

                ++islands;
                queue<pair<int, int>> cells;
                cells.push({row, col});
                grid[row][col] = '0'; // Mark visited when enqueued.

                while (!cells.empty()) {
                    auto [currentRow, currentCol] = cells.front();
                    cells.pop();

                    for (const auto& direction : directions) {
                        int nextRow = currentRow + direction[0];
                        int nextCol = currentCol + direction[1];

                        if (nextRow >= 0 && nextRow < rows &&
                            nextCol >= 0 && nextCol < cols &&
                            grid[nextRow][nextCol] == '1') {
                            grid[nextRow][nextCol] = '0';
                            cells.push({nextRow, nextCol});
                        }
                    }
                }
            }
        }

        return islands;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of islands: " << solution.numIslands(grid) << endl; // 3
    return 0;
}
