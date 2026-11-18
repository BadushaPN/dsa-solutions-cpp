#include <bits/stdc++.h>
using namespace std;

// Graph node definition
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int value) : val(value), neighbors() {}
};

// LeetCode 133: Clone Graph
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> copies;
        copies[node] = new Node(node->val);
        queue<Node*> pending;
        pending.push(node);

        while (!pending.empty()) {
            Node* original = pending.front();
            pending.pop();

            for (Node* neighbor : original->neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor->val);
                    pending.push(neighbor);
                }
                copies[original]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};

int main() {
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);

    one->neighbors = {two, four};
    two->neighbors = {one, three};
    three->neighbors = {two, four};
    four->neighbors = {one, three};

    Solution solution;
    Node* cloned = solution.cloneGraph(one);

    cout << "Original root: " << one->val << '\n';
    cout << "Cloned root: " << cloned->val << '\n';

    delete cloned;
    delete one;
    delete two;
    delete three;
    delete four;

    return 0;
}
