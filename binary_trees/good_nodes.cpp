#include <bits/stdc++.h>
using namespace std;

// LeetCode 1448: Count Good Nodes in Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* leftNode, TreeNode* rightNode)
        : val(value), left(leftNode), right(rightNode) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int count = 0;
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({root, root->val});

        while (!nodes.empty()) {
            auto [node, maximumSoFar] = nodes.top();
            nodes.pop();

            if (node->val >= maximumSoFar) {
                ++count;
                maximumSoFar = node->val;
            }

            if (node->right != nullptr) {
                nodes.push({node->right, maximumSoFar});
            }
            if (node->left != nullptr) {
                nodes.push({node->left, maximumSoFar});
            }
        }

        return count;
    }
};

int main() {
    //       3
    //      / \
    //     1   4
    //    /   / \
    //   3   1   5
    TreeNode* root = new TreeNode(
        3,
        new TreeNode(1, new TreeNode(3), nullptr),
        new TreeNode(4, new TreeNode(1), new TreeNode(5))
    );

    Solution solution;
    cout << "Good nodes: " << solution.goodNodes(root) << '\n'; // 4

    return 0;
}
