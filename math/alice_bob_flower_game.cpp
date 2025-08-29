#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = (n + 1) / 2;   
        long long evenN = n / 2;        
        long long oddM = (m + 1) / 2;   
        long long evenM = m / 2;        

    
        return oddN * evenM + evenN * oddM;
    }
};

int main() {
    Solution sol;

    int n = 3, m = 4;
    cout << "Number of winning pairs: " << sol.flowerGame(n, m) << endl;
    

    return 0;
}
