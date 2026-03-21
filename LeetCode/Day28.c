**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        // Create a dummy node to simplify building the result list
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode* current = dummy;

    int carry = 0;

    // Loop while there are digits in either list
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        // Create a new node for the digit (sum % 10)
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        // Append to result list
        current->next = newNode;
        current = newNode;

        // Advance l1 and l2
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    // The actual result list starts at dummy->next
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;

}