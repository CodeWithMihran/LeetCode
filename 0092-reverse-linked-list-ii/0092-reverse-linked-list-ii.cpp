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

    ListNode* reverseList(ListNode* head, int left, int right, ListNode* &nextNode) {
        int index = left;
        ListNode *prev = NULL, *curr = head, *next = NULL;

        while(index != right+1) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            index++; 
        }
        nextNode = curr;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right) return head;

        int index = 1;
        ListNode *curr = head, *prevNode = NULL, *nextNode = NULL, *firstNode = NULL;

        while(index != left) {
            index++;
            prevNode = curr;
            curr = curr->next;
        }
        firstNode = curr;
        if(prevNode) prevNode->next = reverseList(curr, left, right, nextNode);
        else head = reverseList(curr, left, right, nextNode);

        firstNode->next = nextNode;
        return head;
    }
};