#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res1 = sol.groupAnagrams(strs1);
    for (const auto& group : res1) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i] << (i + 1 < group.size() ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;

    vector<string> strs2 = {""};
    vector<vector<string>> res2 = sol.groupAnagrams(strs2);
    for (const auto& group : res2) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i] << (i + 1 < group.size() ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
