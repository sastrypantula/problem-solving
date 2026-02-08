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
int chk(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int leftht=1+chk(root->left);
    int rightht=1+chk(root->right);
    return max(leftht,rightht);
}
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }

        int leftheight=chk(root->left);
        int rightheight=chk(root->right);
        if(abs(leftheight-rightheight)>1){
            return false;
        }
        // we should check for every node
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};