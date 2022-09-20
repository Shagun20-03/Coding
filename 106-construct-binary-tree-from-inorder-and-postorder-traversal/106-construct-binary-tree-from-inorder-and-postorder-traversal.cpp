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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& mp)
    {
        if(postStart>postEnd || inStart>inEnd)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-inStart;
        
        root->left=build(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1, mp);
        root->right=build(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, mp);
        
        return root;
    }
};