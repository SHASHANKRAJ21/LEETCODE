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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // If the list becomes empty
        if (head == nullptr)
            return nullptr;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while (temp != NULL) {
            if (temp->val == val) {
                prev->next = temp->next;
                temp = temp->next; // move temp forward after deletion
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};