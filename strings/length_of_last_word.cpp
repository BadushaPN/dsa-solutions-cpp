#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0, i = n - 1;

        while (i >= 0 && s[i] == ' ') i--;

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("Hello World") << endl;                
    cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << endl; 
    cout << sol.lengthOfLastWord("luffy is still joyboy") << endl;      
    return 0;
}
