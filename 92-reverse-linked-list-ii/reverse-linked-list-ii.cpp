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
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* leftpre = dummy;
        ListNode* front;// nextnode;
            ListNode* temp = head;
        // abbb hum, for loop ka use krker pahuch jayenga left tak kuki hume
        // heft aur right ka beech ka reverse krna ha theeeka;
        for (int i = 0; i < left - 1; i++) {
            temp = temp->next;
            leftpre = leftpre->next;
        }
        ListNode* newhead = temp;
        ListNode* prev = NULL;
        for (int i = 0; i < right - left+1; i++){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        leftpre->next=prev;
        newhead->next=temp;
        return dummy->next;
    }
};