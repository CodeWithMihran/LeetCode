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
        if(head==NULL)
            return head;
        if(k==0)
            return head;
        int length=0;
        ListNode* curr=head;
        ListNode* tail=NULL;
        while(curr!=NULL){
            length++;
            tail=curr;
            curr=curr->next;
        }
        if(k==length)
            return head;
        if(k>length)
        
            k=k%length;
        int idx=0;
        curr=head;
        while(idx<length-k-1){
            curr=curr->next;
            idx++;
        }
        tail->next=head;
        ListNode* newHead=curr->next;
        curr->next=NULL;
        return newHead;
    }
};