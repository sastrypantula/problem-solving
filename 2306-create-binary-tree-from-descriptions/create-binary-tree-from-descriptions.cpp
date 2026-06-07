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
   unordered_map<int,vector<int>> mymap;
        unordered_map<int,int> freq;
        TreeNode* func(int r){
            TreeNode* root=new TreeNode(r);
            int a=-1;
            int b=-1;
            if(mymap.count(r) && mymap[r].size()>1){
                if(freq[mymap[r][0]]==1){
                    a=mymap[r][0];
                    b=mymap[r][1];
                }
                else{
                    a=mymap[r][1];
                    b=mymap[r][0];
                }
            }
            if(mymap.count(r) && mymap[r].size()==1){
                if(freq[mymap[r][0]]==1){
                    a=mymap[r][0];
                }
                else{
                    b=mymap[r][0];
                }
            }
            if(a==-1){
                root->left=NULL;
            }
            else{
                  root->left=func(a);
            }
            if(b==-1){
                root->right=NULL;
            }
            else{
                root->right=func(b);
            }
            return root;
        }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
     
        int root=0;
        for(auto it:descriptions){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            mymap[a].push_back(b);
            freq[b]=c;
        }
        for(auto it:mymap){
            int key=it.first;
            if(!freq.count(key)){
                root=key;
                break;
            }
        }
        return func(root);
        
    }
};