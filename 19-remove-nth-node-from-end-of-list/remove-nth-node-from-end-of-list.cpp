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
        if(!head || !head->next){
            return nullptr;
        }
        ListNode *temp = head;
        int count =0;
        while(temp){
            count ++;
            temp = temp->next;
        }
        int indexToDelete = count - n;

        if (indexToDelete == 0) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        int a =0;
        temp = head;
        while(temp){
            if(a == indexToDelete-1){
                temp->next = temp->next->next;
                break;
            }
            a++;
            temp = temp->next;
        }
        return head;
        
    }
};