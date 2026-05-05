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
    ListNode* rotateRight(ListNode* head, int k) {
           if (!head || !head->next || k == 0) return head;
        queue<ListNode*> q;
        ListNode* temp=head;
        while(temp!=NULL){
            q.push(temp);
            temp=temp->next;
        }
        int n=q.size();
         k = k % n; 
        int t=n-k;
        while(t>0){
            ListNode* temp1=q.front();
             q.pop();
             q.push(temp1);
             t--;
        }
        head=q.front();
        temp=head;
        q.pop();
        while(!q.empty()){
          temp->next=q.front();
          q.pop();
          temp=temp->next;
        }
        temp->next=nullptr;
        return head;
    }
};