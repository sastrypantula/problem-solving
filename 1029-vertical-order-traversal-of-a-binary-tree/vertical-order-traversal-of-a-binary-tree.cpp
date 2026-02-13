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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mymap;
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});
       while(!q.empty()){
        tuple<TreeNode*,int,int> t=q.front();
        q.pop();
        TreeNode* takenNode=get<0> (t);
        int row=get<1> (t);
        int col=get<2> (t);
        mymap[col].push_back({row,takenNode->val});
        if(takenNode->left!=nullptr){
            q.push({takenNode->left,row+1,col-1});
        }
         if(takenNode->right!=nullptr){
            q.push({takenNode->right,row+1,col+1});
        }

       }
       vector<vector<int>> result;
       for(auto &it:mymap){
        int key=it.first;
        vector<pair<int,int>> t=it.second;
        sort(t.begin(),t.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        vector<int> sample;
        for(auto& temp:t){
            sample.push_back(temp.second);
        }
        result.push_back(sample);
       }
       return result;
    }
};