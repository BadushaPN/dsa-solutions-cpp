#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        long long reversed = 0;
        int original = x;

        while (x > 0) {
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }

        return reversed == original;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.isPalindrome(121) << endl;   // true
    cout << sol.isPalindrome(-121) << endl;  // false
    cout << sol.isPalindrome(10) << endl;    // false
    cout << sol.isPalindrome(12321) << endl; // true

    return 0;
}
