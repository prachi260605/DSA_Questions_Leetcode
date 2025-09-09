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
        if(!head || !head->next) return nullptr;
        int cnt =0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp ->next;
        }
        int index = cnt - n;
        if (index == 0) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }
        temp = head;
        while(index-1){
            index--;
            temp = temp->next;
        }
        ListNode *NodeToDelete = temp->next;
        temp->next = temp->next->next;
        NodeToDelete->next = nullptr;
        delete NodeToDelete;
        return head;
        
        
    }
};