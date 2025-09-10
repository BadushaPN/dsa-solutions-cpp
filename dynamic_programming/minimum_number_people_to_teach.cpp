#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, unordered_set<int>> userLanguages;
        for (int i = 0; i < languages.size(); ++i) {
            userLanguages[i + 1] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        unordered_set<int> usersToTeach;
        vector<pair<int, int>> problemFriendships;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            
            for (int lang : userLanguages[u]) {
                if (userLanguages[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }

            if (!canCommunicate) {
                problemFriendships.push_back({u, v});
                usersToTeach.insert(u);
                usersToTeach.insert(v);
            }
        }

        int minToTeach = problemFriendships.empty() ? 0 : n;
        for (int lang = 1; lang <= n; ++lang) {
            int teachCount = 0;

            for (int user : usersToTeach) {
                if (!userLanguages[user].count(lang)) {
                    ++teachCount;
                }
            }

            minToTeach = min(minToTeach, teachCount);
        }

        return minToTeach;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> languages1 = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships1 = {{1, 2}, {1, 3}, {2, 3}};
    cout << solution.minimumTeachings(2, languages1, friendships1) << endl;  

    vector<vector<int>> languages2 = {{2}, {1, 3}, {1, 2}, {3}};
    vector<vector<int>> friendships2 = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    cout << solution.minimumTeachings(3, languages2, friendships2) << endl;  

    return 0;
}
