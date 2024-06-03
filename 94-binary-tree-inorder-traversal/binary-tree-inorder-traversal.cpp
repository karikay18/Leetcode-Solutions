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
// using morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            TreeNode* pre=cur->left;
            if(pre==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;

            }
            else
            {
                while(pre->right!=NULL)
                {
                    pre=pre->right;
                }
                pre->right=cur;
                TreeNode* temp=cur;
                cur=cur->left;
                temp->left=NULL;

            }
        }
        return ans;
    }
};