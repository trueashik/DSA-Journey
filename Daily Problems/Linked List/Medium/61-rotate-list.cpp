// ═══════════════════════════════════════════════════════
// Problem: 61. Rotate List
// Difficulty: Medium
// Topics: Linked List, Two Pointers
// Runtime: 0 ms (Beats 100.0%)
// Memory: 16.4 MB (Beats 63.1%)
// Submitted: May 5, 2026
// Link: https://leetcode.com/problems/rotate-list/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0) return head;

        tail->next = head;

        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
