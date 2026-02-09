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
vector<int> temp;
void chk(TreeNode* root){
    if(root==nullptr){
return;
    }
    chk(root->left);
    temp.push_back(root->val);
    chk(root->right);
}
TreeNode* balance(vector<int>& temp,int low,int high){
    if(low>high){
        return NULL;
    }
    int mid=(low+high)/2;
    TreeNode* newroot=new TreeNode(temp[mid]);
    newroot->left=balance(temp,low,mid-1);
    newroot->right=balance(temp,mid+1,high);
    return newroot;
}
    TreeNode* balanceBST(TreeNode* root) {
        chk(root);
      
        return balance(temp,0,temp.size()-1);
     

    }
};