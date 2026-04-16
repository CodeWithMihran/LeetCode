class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* pre = fake;  
        ListNode* curr = head;    
        while (curr != NULL) {
            while (curr->next != NULL && pre->next->val == curr->next->val)
                curr = curr->next;
            if (pre->next == curr)
                pre = pre->next;
            else
                pre->next = curr->next;
                curr = curr->next;
        }
        return fake->next;
    }
};