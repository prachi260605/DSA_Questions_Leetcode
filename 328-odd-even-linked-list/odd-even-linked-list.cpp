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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* temp = head;
        ListNode* nn = new ListNode(temp->val);  // first odd node
        ListNode* curr = nn;
        temp = temp->next;

        // process odd nodes
        while (temp && temp->next) {
            curr->next = new ListNode(temp->next->val);
            curr = curr->next;
            temp = temp->next->next;
        }

        // process even nodes
        temp = head->next;
        while (temp) {
            curr->next = new ListNode(temp->val);
            curr = curr->next;
            if (temp->next) temp = temp->next->next;
            else break;
        }

        return nn;
    }
};
