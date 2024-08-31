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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right){
        // Base cases
        if (left == 0) return right;
        if (right == 0) return left;

        // Dummy node to help easily build the merged list
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        // Merge the two lists
        while (left && right) {
            if (left->val <= right->val) {
                mptr->next = left;
                left = left->next;
            } else {
                mptr->next = right;
                right = right->next;
            }
            mptr = mptr->next; // Move mptr to the next node
        }

        // Attach the remaining part of the left or right list, if any
        if (left) {
            mptr->next = left;
        } else {
            mptr->next = right;
        }

        return ans->next; // Return the merged list starting from the next node after dummy
    }
};