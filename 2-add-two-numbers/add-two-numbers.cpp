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
ListNode* reverse(  ListNode* curr,  ListNode* prev){
    if(curr==NULL){
        return prev;
    }
      ListNode* front=curr->next;
      curr->next=prev;

      return reverse(front,curr);
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* prev=NULL;
        // ListNode* first=reverse(l1,prev);
        // ListNode* second=reverse(l2,prev);
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* head=new ListNode(0);
          ListNode* tail=head;
          int carry=0;
          while(curr1!=NULL && curr2!=NULL){
            int sum=curr1->val+curr2->val+carry;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            curr1=curr1->next;
            curr2=curr2->next;
            carry=sum/10;
          }
          while(curr1!=NULL){
            int sum=curr1->val+carry;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            curr1=curr1->next;
            carry=sum/10;
          }
             while(curr2!=NULL){
            int sum=curr2->val+carry;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            curr2=curr2->next;
            carry=sum/10;
          }
          while(carry!=0){
            tail->next=new ListNode(carry);
            tail=tail->next;
            carry=carry/10;
          }
        head=head->next;
        return head;

    }
};