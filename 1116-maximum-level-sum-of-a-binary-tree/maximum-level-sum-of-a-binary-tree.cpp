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
    int maxLevelSum(TreeNode* root) {
        int level=0;
        int ans=INT_MIN;
        int sum=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
         int curr=0;
        while(!q.empty()){
         if(q.front()==nullptr){
            q.pop();
            level++;
             if(sum<curr){
                ans=level;
                sum=curr;
             }
             curr=0;
             if(!q.empty()){
             q.push(nullptr);
             
             }
            
         }
         else{
         TreeNode* t=q.front();
         q.pop();
         curr+=t->val;
         if(t->left!=nullptr){
       q.push(t->left);
         }
         if(t->right!=nullptr){
           q.push(t->right);
         }
     }
        }
     return ans;
    }
};