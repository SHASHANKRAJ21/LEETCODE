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
    ListNode* reverseusingrecursion(ListNode* prev,ListNode* curr) {
        if(curr==NULL){
            return prev;
        }
        ListNode* newnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newnode;
        return reverseusingrecursion(prev,curr);


        
    }
    ListNode* middlenode(ListNode*head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    bool comparelist(ListNode*head1,ListNode*head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val!=head2->val){
                return false;

            }
            else{
                head1=head1->next;
                head2=head2->next;
            }
        }
        return true;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* midlle=middlenode(head);
        ListNode* head2=midlle->next;
        midlle->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head2;
        head2=reverseusingrecursion(prev,curr);
        bool ans=comparelist(head,head2);
        return ans;    

    }
};