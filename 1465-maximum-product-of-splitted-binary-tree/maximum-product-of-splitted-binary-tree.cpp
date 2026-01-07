// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
//  // first thought of a wrong solution next understood the approach

//  const int MOD=1e9+7;
//  long long totalsum=0;
//  long long ans=LLONG_MIN;
// class Solution {
// public:
// long long solve(TreeNode* root){
//     if(root==NULL){
//         return 0;
//     }
//     long long left=solve(root->left);
//     long long right=solve(root->right);
//     return root->val+left+right;
// }
// long long func(TreeNode* root){

// }
//     int maxProduct(TreeNode* root) {
//        totalsum=solve(root);
//        long long n=func(root);
//     }
// };

class Solution {
public:
    
    long M = 1e9+7;
    long totalSum = 0, maxP = 0;
    
    int findTotalSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSubtreeSum  = findTotalSum(root->left);
        int rightSubtreeSum = findTotalSum(root->right);
        int sum             = root->val + leftSubtreeSum + rightSubtreeSum;
        
        maxP = max(maxP, (totalSum - sum) * sum);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        maxP = 0;
        
        totalSum = findTotalSum(root);
        
        
        findTotalSum(root);
        
        return maxP%M;
    }
};
