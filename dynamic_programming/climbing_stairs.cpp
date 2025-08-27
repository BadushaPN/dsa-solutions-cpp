#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int first = 1, second = 2, ways = 0;
        for (int i = 3; i <= n; i++) {
            ways = first + second;
            first = second;
            second = ways;
        }
        return second;
    }
};

int main() {
    Solution solution;
    
    int n1 = 2, n2 = 3;
    cout << "Input: " << n1 << " -> Output: " << solution.climbStairs(n1) << endl;
    cout << "Input: " << n2 << " -> Output: " << solution.climbStairs(n2) << endl;

    return 0;
}
