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
class Solution {
private:
    TreeNode* prev;
    TreeNode* first;   //first violation
    TreeNode* mid;
    TreeNode* last; //2nd violation
    
private:
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val))
        {
            // if this is the first violation mark this node as first and middle
            if(first==NULL){
                first=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first=mid=last=NULL;
        prev =new TreeNode(INT_MIN);    //first node that we encounter in inorder 
        inorder(root);
        if(first && last)
            swap(first->val, last->val);
        else if(first && mid)
            swap(first->val, mid->val);
    }
};