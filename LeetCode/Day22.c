/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;      // Step 1: store next
        curr->next = prev;      // Step 2: reverse link
        prev = curr;            // Step 3: move prev forward
        curr = next;            // Step 4: move curr forward
    }
    
    return prev;   // new head
}