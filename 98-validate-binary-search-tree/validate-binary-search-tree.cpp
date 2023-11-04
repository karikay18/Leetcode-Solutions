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
    void helper(TreeNode* root,long long min_val,long long max_val, bool &flag)
    {
        if(root==NULL){
            return;
        }
        if (root->val <= min_val || root->val >= max_val) {
            flag = false;
            return;
        }
        helper(root->left, min_val, root->val, flag);
        helper(root->right, root->val, max_val, flag);
        

    }
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        helper(root, LLONG_MIN, LLONG_MAX, flag);
        return flag;
        
    }
};