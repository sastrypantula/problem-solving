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
    ListNode* partition(ListNode* head, int x) {
        queue<int> q1, q2;
        ListNode* temp = head;

        
        while (temp != nullptr) {
            if (temp->val < x) q1.push(temp->val);
            else q2.push(temp->val);
            temp = temp->next;
        }

        
        if (q1.empty() && q2.empty()) return nullptr;
        ListNode* newHead = nullptr;
        ListNode* t = nullptr;

        
        if (!q1.empty()) {
            newHead = new ListNode(q1.front());
            q1.pop();
            t = newHead;
            while (!q1.empty()) {
                t->next = new ListNode(q1.front());
                q1.pop();
                t = t->next;
            }
        }

        
        if (!q2.empty()) {
            if (newHead == nullptr) {
                newHead = new ListNode(q2.front());
                q2.pop();
                t = newHead;
            }
            while (!q2.empty()) {
                t->next = new ListNode(q2.front());
                q2.pop();
                t = t->next;
            }
        }

        return newHead;
    }
};