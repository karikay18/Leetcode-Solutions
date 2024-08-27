class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        if (left != nullptr) {
            current->next = left;
        } else {
            current->next = right;
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);

        return mergeLists(left, right);
    }
};