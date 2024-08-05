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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        // Move to the node just before the reversal starts
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* start = prev;  // Node before reversal starts
        ListNode* end = curr;    // Will be the last node after reversal
        
        // Reverse the sublist
        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Connect the reversed portion back to the list
        if (start) {
            start->next = prev;
        } else {
            head = prev;  // If reversal started at head
        }
        end->next = curr;
        
        return head;
    }
};