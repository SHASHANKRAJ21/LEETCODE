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
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Traverse to end recursively and remove bad nodes
        head->next = removeNodes(head->next);

        // Step 2: If next node is greater, skip current node
        if (head->next && head->val < head->next->val) {
            return head->next;
        }

        return head;
    }
};
