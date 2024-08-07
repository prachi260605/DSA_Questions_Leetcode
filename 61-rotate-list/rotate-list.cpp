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

        if (head == NULL || head->next == NULL || k == 0)
            return head;
        // step 1: Find Length
        int n = 1;
        // step 2: find tail pointer
        ListNode* tail = head;
        // Step 3 :
        while (tail->next) {
            n++;
            tail = tail->next;
        }
        k = k % n;
        if (k == 0)
            return head;

        tail->next = head;

        // traverse the n-k node
        ListNode* temp = head;
        for (int i = 1; i < n - k; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};