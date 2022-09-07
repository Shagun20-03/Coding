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
    
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {  
        if(head->next == NULL || head==NULL)
            return true;
        
        ListNode* middle=getMid(head);
        
        ListNode* temp=middle->next;
        middle->next=reverse(temp);
        
        ListNode* head1=head;
        ListNode* head2=middle->next;
        while(head2!=NULL)
        {
            if(head1->val != head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        //optional repeat step2 for making original linked list
        temp=middle->next;
        middle->next=reverse(temp);
        
        return true;
    }
};