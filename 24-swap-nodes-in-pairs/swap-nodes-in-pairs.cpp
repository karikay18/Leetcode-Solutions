class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* newHead = head->next;  // new head after swapping the first pair
        ListNode* cur = head;
        ListNode* prev = NULL;
        
        while (cur != NULL && cur->next != NULL) {
            ListNode* nextPair = cur->next->next;
            ListNode* second = cur->next;
            
            second->next = cur;
            cur->next = nextPair;
            
            if (prev != NULL) {
                prev->next = second;
            }
            
            prev = cur;
            cur = nextPair;
        }
        
        return newHead;
    }
};