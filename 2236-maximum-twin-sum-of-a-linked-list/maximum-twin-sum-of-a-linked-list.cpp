/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int sum=0;
        vector<int> res;
        ListNode* temp=head;
        while(temp!=nullptr){
            res.push_back(temp->val);
            temp=temp->next;
        }
        int n=res.size();
        int i=0;
        int j=n-1;
      
        while(i<j){
            sum=max(sum,(res[i]+res[j]));
            cout<<sum<<endl;
          i++;
          j--;
        }
        return sum;
    }
};