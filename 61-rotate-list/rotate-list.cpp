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
        if (head == NULL || head->next == NULL || k == 0) return head;

        // Calculate the length of the list
        int len = 1; // start from 1 because we are starting from head
        ListNode* tail = head;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        // Calculate the effective rotations needed
        k = k % len;
        if (k == 0) return head;

        // Make the list circular
        tail->next = head;

        // Find the new head and new tail
        int stepsToNewHead = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        // Break the circular list
        newTail->next = NULL;

        return newHead;
    }
};
