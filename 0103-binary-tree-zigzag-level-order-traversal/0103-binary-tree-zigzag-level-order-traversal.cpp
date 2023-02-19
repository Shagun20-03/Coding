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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool LefttoRight=true;  //initially we have assigned traversal from left to right
        
        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int index=LefttoRight? i:(size-i-1);
                row[index]=node->val;
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            //changing the boolean value fromleft to right traversal
            LefttoRight=!LefttoRight;
            ans.push_back(row);
        }
        return ans;
    }
};