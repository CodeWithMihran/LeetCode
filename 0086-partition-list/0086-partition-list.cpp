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
        ListNode *curr = head, *head1 = NULL, *head2 = NULL, *curr1 = NULL, *curr2 = NULL, *next = NULL;
        int smaller = 1, large = 1;

        while(curr) {

            next = curr->next;

            curr->next = NULL;

            if(curr->val < x) {
                if(smaller > 0) {
                    head1 = curr;
                    curr1 = head1;
                    smaller--;
                }
                else {
                    curr1->next = curr;
                    curr1 = curr1->next;
                }
            } else {
                if(large > 0) {
                    head2 = curr;
                    curr2 = head2;
                    large--;
                }
                else {
                    curr2->next = curr;
                    curr2 = curr2->next;
                }
            }
            curr = next;
        }
        if(head1 && head2) curr1->next = head2;
        else return head;
        return head1;
    }
};