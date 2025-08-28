#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result.push_back(char(sum % 2 + '0'));
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    string a1 = "11", b1 = "1";
    cout << "Input: a = " << a1 << ", b = " << b1 << "\n";
    cout << "Output: " << sol.addBinary(a1, b1) << "\n\n";

    string a2 = "1010", b2 = "1011";
    cout << "Input: a = " << a2 << ", b = " << b2 << "\n";
    cout << "Output: " << sol.addBinary(a2, b2) << "\n";

    return 0;
}
