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
    void solve(TreeNode* root,vector<int>&res)
    {
        if(root==NULL)return;
        if(root->left!=NULL)
        {
            solve(root->left,res);
            // res.push_back(root->left->val);
        }
        res.push_back(root->val);
        if(root->right!=NULL)
        {
            solve(root->right,res);
            // res.push_back(root->right->val);
        }


    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        solve(root,res);
        return res;
    }
};