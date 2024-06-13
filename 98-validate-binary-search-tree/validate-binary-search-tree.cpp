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
    void solve(TreeNode* root,long long maxi,long long mini,bool &flag)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=maxi || root->val<=mini)
        {
            flag=false;
            return;
            
        }
        solve(root->left,root->val,mini,flag);
        solve(root->right,maxi,root->val,flag);
    }
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        solve(root,LLONG_MAX,LLONG_MIN,flag);
        return flag;
    }
};