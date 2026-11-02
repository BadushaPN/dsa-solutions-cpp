#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto &entry : freq) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(result.begin(), result.end(), [&](int a, int b) {
            return freq[a] > freq[b];
        });

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> res1 = sol.topKFrequent(nums1, 2);
    for (int x : res1) cout << x << " ";
    cout << endl; // 1 2

    vector<int> nums2 = {1};
    vector<int> res2 = sol.topKFrequent(nums2, 1);
    for (int x : res2) cout << x << " ";
    cout << endl; // 1

    vector<int> nums3 = {1, 2, 2, 3, 3, 3};
    vector<int> res3 = sol.topKFrequent(nums3, 2);
    for (int x : res3) cout << x << " ";
    cout << endl; // 3 2

    return 0;
}
