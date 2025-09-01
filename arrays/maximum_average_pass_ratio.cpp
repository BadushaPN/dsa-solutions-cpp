#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    double gain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double, pair<int,int>>> pq;

        
        for (auto &cls : classes) {
            pq.push({gain(cls[0], cls[1]), {cls[0], cls[1]}});
        }

        
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int pass = top.second.first;
            int total = top.second.second;

    
            pass++; total++;

    
            pq.push({gain(pass, total), {pass, total}});
        }

        
        double sum = 0.0;
        while (!pq.empty()) {
            auto cls = pq.top().second; pq.pop();
            sum += (double)cls.first / cls.second;
        }

        return sum / classes.size();
    }
};


int main() {
    Solution sol;
    vector<vector<int>> classes1 = {{1,2},{3,5},{2,2}};
    int extra1 = 2;
    cout << fixed << setprecision(5)
         << sol.maxAverageRatio(classes1, extra1) << endl; 


    vector<vector<int>> classes2 = {{2,4},{3,9},{4,5},{2,10}};
    int extra2 = 4;
    cout << fixed << setprecision(5)
         << sol.maxAverageRatio(classes2, extra2) << endl; 
    
}
