#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long X = 1LL * num1 - 1LL * k * num2;
            if (X < 0) continue;
            int bits = __builtin_popcountll(X);
            if (bits <= k && k <= X) return k;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.makeTheIntegerZero(3, -2) << endl; 
    cout << sol.makeTheIntegerZero(5, 7) << endl;  
    return 0;
}
