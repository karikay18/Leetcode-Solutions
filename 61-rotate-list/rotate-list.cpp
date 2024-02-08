class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // If the list is empty or rotation is unnecessary, return the original head
        
        int size = 1; // Start from 1 since we count the head node
        ListNode* temp = head;
        
        while (temp->next) {
            temp = temp->next;
            size++;
        }
        
        temp->next = head; // Make the list circular
        
       k %= size; // Handle cases where k is larger than the size of the list
        
        int stepsToNewHead = size - k;
        temp = head;
        
        while (stepsToNewHead > 1) { // Stop at the node before the new head
            temp = temp->next;
            stepsToNewHead--;
        }
        
        ListNode* newHead = temp->next;
        temp->next = nullptr; // Disconnect the list
        
        return newHead;
    }
};
