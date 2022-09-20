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
public:
    // TreeNode* curr=nullptr;
    void flatten(TreeNode* root) {
        //recursive approach
        
//         if(root==nullptr)
//             return;
        
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right=prev;
//         root->left=nullptr;
//         prev=root;
        TreeNode* curr=root;

        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode* pre=curr->left;
                while(pre->right!=nullptr)
                {
                    pre=pre->right;
                }
                pre->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};