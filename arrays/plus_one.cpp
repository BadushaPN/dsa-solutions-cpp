    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; 
            }
            digits[i] = 0; 
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;

    vector<int> digits1 = {1, 2, 3};
    vector<int> res1 = sol.plusOne(digits1);
    for (int d : res1) cout << d << " "; 
    cout << endl;

    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> res2 = sol.plusOne(digits2);
    for (int d : res2) cout << d << " "; 
    cout << endl;

    vector<int> digits3 = {9};
    vector<int> res3 = sol.plusOne(digits3);
    for (int d : res3) cout << d << " "; 
    cout << endl;

    return 0;
}
