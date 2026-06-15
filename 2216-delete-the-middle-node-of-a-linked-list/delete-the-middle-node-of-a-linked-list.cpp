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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        if(n==1){
            return nullptr;
        }
        int mid=n/2;
        int count=0;
        temp=NULL;
        ListNode* temp1=head;
        while(temp1!=nullptr){
          if(count==mid){
            temp->next=temp1->next;
            if(temp1->next!=nullptr){
            temp1=temp1->next;
            }
            else{
                temp1=nullptr;
            }
          }
          else{
          temp=temp1;
          temp1=temp1->next;
          }
          count++;
        }
        return head;
    }
};