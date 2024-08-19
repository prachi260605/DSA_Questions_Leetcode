class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* ans=new ListNode(-1);
        ListNode* tempAns=ans;
        int c=0;
        while(temp){
            if(temp and temp->val!=0){
                c+=temp->val;
            }
            else if(temp and temp->val==0){
                ListNode* t=new ListNode(c);
                tempAns->next=t;
                tempAns=tempAns->next;
                c=0;
            }
            temp=temp->next;
        }
        return ans->next;
    }
};