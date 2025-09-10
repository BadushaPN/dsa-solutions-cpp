#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
      const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);

        dp[1] = 1;  

        for (int day = 1; day <= n; ++day) {
            if (dp[day] == 0) continue;

            int startShareDay = day + delay;
            int forgetDay = day + forget;

            for (int j = startShareDay; j < forgetDay && j <= n; ++j) {
                dp[j] = (dp[j] + dp[day]) % MOD;
            }
        }

        long long result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1) {
                result = (result + dp[day]) % MOD;
            }
        }
        return result;
    }
    
};

int main() {
    Solution solution;
    int n = 6, delay = 2, forget = 4;
    cout << "Output: " << solution.peopleAwareOfSecret(n, delay, forget) << endl;
    
    n = 4, delay = 1, forget = 3;
    cout << "Output: " << solution.peopleAwareOfSecret(n, delay, forget) << endl;
    
    return 0;
}
