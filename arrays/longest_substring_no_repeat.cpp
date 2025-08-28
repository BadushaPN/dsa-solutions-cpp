#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1); 
    int maxLen = 0, start = -1;

    for (int i = 0; i < s.size(); i++) {
        if (lastIndex[s[i]] > start) {
            start = lastIndex[s[i]];
        }
        lastIndex[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Length of Longest Substring Without Repeating Characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
