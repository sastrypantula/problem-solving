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
   int ans=0;
     int bintosum(string s){
    int temp=0;
    int n=s.length();
    int i=n-1;
    int k=0;
    while(i>=0){
      temp=temp+((s[i]-'0')*pow(2,k));
      k++;
      i--;
    }
    return temp;
   }
   void func(TreeNode* root,string& temp){
      if(root==NULL){
        return;
      }
      temp.push_back(root->val+'0');
      func(root->left,temp);
      func(root->right,temp);
      if(root->left==NULL && root->right==NULL){
       ans=ans+bintosum(temp);
      }
       cout<<temp<<endl;
       temp.pop_back();
       return;

   }
    int sumRootToLeaf(TreeNode* root) {
        string temp="";
        func(root,temp);
        return ans;
    }
};