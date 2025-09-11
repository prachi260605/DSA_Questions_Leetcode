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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* front;

        while(curr){
            front = curr->next;
            curr->next =prev;
            prev = curr;
            curr = front;
        }
        return prev;

    }
    ListNode* findKthNode(ListNode* temp, int k){
        k = k-1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while(temp){
            ListNode* kthNode = findKthNode(temp, k);
            if(!kthNode){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
        
    }
};