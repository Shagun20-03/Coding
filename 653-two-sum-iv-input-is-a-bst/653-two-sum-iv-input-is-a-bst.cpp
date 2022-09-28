/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BstIterator{
    stack<TreeNode* > st;
    bool before=true;
    
public:
    BstIterator(TreeNode* root, bool isbefore){
        before=isbefore;
        pushAll(root);
    }
    
    bool hasNext(){
        return (!st.empty());
    } 
    
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(before==false){  //next element
            pushAll(temp->right);   //go to right and push all left nodes
        }else{
            pushAll(temp->left);
        }
        return temp->val;
    }
        
private:
    void pushAll(TreeNode* node){
        while(node!=NULL)
        {
            st.push(node);
            if(before==true){
                node=node->right;
            }else{
                node=node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        BstIterator l(root, false);  //creating object of class BstIterator for next
        BstIterator r(root, true);  //creating object of class BstIterator for before
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=l.next();
            else
                j=r.next();
        }
        return false;
    }
};