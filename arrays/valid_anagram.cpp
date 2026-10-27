#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (char c : t) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0) return false;
        }

        for (int x : freq) {
            if (x != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.isAnagram("anagram", "nagaram") << endl; // true
    cout << sol.isAnagram("rat", "car") << endl; // false
    cout << sol.isAnagram("ab", "a") << endl; // false
    cout << sol.isAnagram("listen", "silent") << endl; // true

    return 0;
}
