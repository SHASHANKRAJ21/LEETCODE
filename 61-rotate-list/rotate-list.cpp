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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
        ListNode*curr=head;
        int length=1;
        while(curr->next){
            curr=curr->next;
            length++;
        }
        curr->next=head;
        k=k%length;
        int newlength=length-k;
        ListNode*tail=head;
        for(int i=1;i<newlength;i++){
            tail=tail->next;
        }
        ListNode * newhead=tail->next;
        tail->next=nullptr;
        return newhead;
        
    }
};