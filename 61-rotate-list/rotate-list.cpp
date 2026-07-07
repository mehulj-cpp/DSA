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
        if(head == NULL || head -> next == NULL || k == 0) {
            return head;
        }

        // Find the length and tail
        ListNode* tail = head;
        int length = 1;
        while(tail -> next) {
            tail = tail -> next;
            length++;
        }

        // Make it circular
        tail -> next = head;

        // Find new length
        k = k % length;
        int stepsToNewTail = length - k;

        ListNode* newTail = head;
        for(int i=1; i < stepsToNewTail; i++) {
            newTail = newTail -> next;
        }

        // Break the link
        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;

        return newHead;

    }
};