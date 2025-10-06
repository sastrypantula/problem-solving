/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void func(TreeNode* root, int depth, int& minDepth) {
        if (!root) return;

        
        if (!root->left && !root->right) {
            minDepth = min(minDepth, depth);
            return;
        }

        func(root->left, depth + 1, minDepth);
        func(root->right, depth + 1, minDepth);
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int minDepthVal = INT_MAX;
        func(root, 1, minDepthVal);
        return minDepthVal;

    }
};