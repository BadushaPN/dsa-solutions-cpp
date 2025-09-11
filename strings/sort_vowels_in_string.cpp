#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> vowelChars;
        
  
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                vowelChars.push_back(c);
            }
        }
      
        sort(vowelChars.begin(), vowelChars.end());
    
        int index = 0;
        for (char &c : s) {
            if (vowels.find(c) != string::npos) {
                c = vowelChars[index++];
            }
        }
        
        return s;
    }
};

int main() {
    Solution solution;
    
    string s1 = "lEetcOde";
    string s2 = "lYmpH";
    
    cout << "Original: " << s1 << " -> Sorted Vowels: " << solution.sortVowels(s1) << endl;
    cout << "Original: " << s2 << " -> Sorted Vowels: " << solution.sortVowels(s2) << endl;
    
    return 0;
}
