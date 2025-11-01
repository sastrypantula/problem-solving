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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>myset(nums.begin(),nums.end());
        // while(head!=NULL && myset.find(head->val)!=myset.end()){
        //     head=head->next;
        // } 
        // ListNode* temp=head;
        // ListNode* prev=head;
        // temp=temp->next;
        // while(temp!=nullptr){
        //     if(myset.find(temp->val)==myset.end()){
        //            prev->next=temp;
        //            prev=temp;
        //     }
        //     temp=temp->next;
        // }
        // if( head->next!=nullptr && myset.find(head->next->val)!=myset.end()){
        //     head->next=nullptr;
        // }
        // return head;


         while (head != nullptr && myset.count(head->val)) {
        head = head->next;
    }

    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp != nullptr) {
        if (myset.count(temp->val)) {
            if (prev != nullptr) {
                prev->next = temp->next;
            }
        } else {
            prev = temp;
        }
        temp = temp->next;
    }

    return head;
    }
};