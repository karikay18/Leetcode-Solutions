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
     vector<vector<int>>res;
     if (root == nullptr) return res;
     queue<TreeNode*>q;
     q.push(root);
     int flag=1;
     while(!q.empty())
     {
        flag=flag*(-1);
        int s=q.size();
        vector<int>level;
        for(int i=0;i<s;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
            if(flag==1)
            {
                reverse(level.begin(),level.end());
            }
        res.push_back(level);
     }
     return res;   
    }
};