#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (hasNoZero(a) && hasNoZero(b)) {
                return {a, b};
            }
        }
        return {};
    }

private:
    bool hasNoZero(int num) {
        while (num > 0) {
            if (num % 10 == 0)
                return false;
            num /= 10;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 11; 
    vector<int> result = sol.getNoZeroIntegers(n);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


