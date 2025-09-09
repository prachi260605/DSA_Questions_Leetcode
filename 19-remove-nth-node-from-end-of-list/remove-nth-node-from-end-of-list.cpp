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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* fast = head;
        while(n){
            n--;
            fast = fast->next;
        }
        if(fast == nullptr){
            ListNode* NodeToDelete = head;
            head = head->next;
            delete NodeToDelete;
            return head;
        }
        ListNode* slow = head;
        while(fast->next){
            slow = slow->next;
            fast = fast ->next;
        }

        ListNode* NodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete NodeToDelete;
        return head;
        
    }
};