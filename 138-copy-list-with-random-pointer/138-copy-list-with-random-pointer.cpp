/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter=head;
        
        // First round: make copy of each node,
  // and link them together side-by-side in a single list.
        while(iter!=NULL)
        {
            Node* copy=iter->next;
            iter->next=new Node(iter->val);
            iter->next->next=copy;
            iter=copy;
        }
         // Second round: assign random pointers for the copy nodes.
        iter=head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL){
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;       
        }
         // Third round: restore the original list, and extract the copy list.
    
        Node* pseudoHead=new Node(0);
        Node* copyIter=pseudoHead;
        
        while(head!=NULL)
        {
            copyIter->next=head->next;
            copyIter=copyIter->next;
            
            head->next = head->next->next;
            head=head->next;
        }
        return pseudoHead->next;
        
        //2nd approach
        // map<Node*, Node*> m;
        // int i=0;
        // Node* ptr = head;
        // while (ptr) {
        //     m[ptr] =new Node(ptr->val);
        //     ptr = ptr->next;
        // }
        // ptr = head;
        // while (ptr) {
        //     m[ptr]->next = m[ptr->next];
        //     m[ptr]->random = m[ptr->random];
        //     ptr = ptr->next;
        // }
        // return m[head];
    }
};