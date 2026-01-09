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
unordered_map<int,int> mymap;
int max_depth=0;
void depth(TreeNode* root,int d){
    if(root==nullptr){
       return;
    }
    mymap[root->val]=d;
    max_depth=max(max_depth,d);
    depth(root->left,d+1);
    depth(root->right,d+1);
}

TreeNode* LCA(TreeNode* root){
    if(root==NULL|| mymap[root->val]==max_depth){
        return root;
    }
    TreeNode* left=LCA(root->left);
    TreeNode* right=LCA(root->right);
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    if(left!=nullptr){
        return left;
    }
    if(right!=nullptr){
        return right;
    }
    return nullptr;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root,0);
        // this is the LCA type question once read the question again u will be figure out this 
        return LCA(root);
    }
};