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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode(0); //dummy node
        temp->next=head;
        
        ListNode* fast=temp;
        ListNode* slow=temp;
        
        //for first iteration of fast till nth node
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        //iteration of fast till null and slow till nth node
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next=slow->next->next;
        return temp->next;
    }
};