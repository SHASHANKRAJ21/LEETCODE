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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *>ans(k);
        ListNode * current=head;
        int count=0;
        while(current!=NULL){
            count++;
            current=current->next;
        }
        int splitsize=count/k;
        int remainingnodes=count%k;  
        current=head;
        ListNode *prev=current;
        for(int i=0;i<k;i++){
            ListNode *newpart=current;
            int currentsize=splitsize;
            if(remainingnodes>0){
                remainingnodes--;
                currentsize++;
            }
            int j=0;
            while(j<currentsize){
                prev=current;
                if(current!=NULL){
                    current=current->next;
                }
                j++;
            }
            if(prev!=NULL){
                prev->next=NULL;
            }
            ans[i]=newpart;
        }
        return ans;      
    }
};