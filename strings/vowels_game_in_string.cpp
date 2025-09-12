#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool vowelsGame(string s) {
     unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        int vowelCount = 0;
        
        for (char c : s) {
            if (vowels.find(c) != vowels.end()) {
                vowelCount++;
            }
        }

        return vowelCount % 2 == 1;
    }
};

int main() {
    Solution solution;
    
    string s1 = "leetcoder";
    string s2 = "ifld";
    
    cout << "s = " << s1 << " -> Alice wins: " 
         << (solution.vowelsGame(s1) ? "true" : "false") << endl;
    
    cout << "s = " << s2 << " -> Alice wins: " 
         << (solution.vowelsGame(s2) ? "true" : "false") << endl;
    
    return 0;
}
