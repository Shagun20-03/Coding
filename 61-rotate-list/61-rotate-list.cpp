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
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* curr=head;
        int len=1;
        while(curr->next!=NULL){
            curr=curr->next;
            len++;
        }
        curr->next=head;
        k=k%len;
        k=len-k;
        while(k--)
            curr=curr->next;
        
        //now new curr is at len-k means node just before k
        head=curr->next;    //from where the rotation starts
        curr->next=NULL;
        return head;
    }
};