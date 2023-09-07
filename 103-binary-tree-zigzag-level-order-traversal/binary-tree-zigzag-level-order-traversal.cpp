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
        vector<vector<int>>ans;
       if(root==NULL) return ans;
       queue<TreeNode*>NQ;
       NQ.push(root); 
       bool leftToRight = true;
       while(!NQ.empty())
       {    
           int size=NQ.size();
           vector<int>row(size);
           for(int i=0;i<size;i++)
           {
               TreeNode* node=NQ.front();
               NQ.pop();
               int index=(leftToRight)?i:(size-i-1);
               row[index]=node->val;
               if(node->left)
               {
                   NQ.push(node->left);
               }
               if(node->right)
               {
                   NQ.push(node->right);
               }
           }
           leftToRight = !leftToRight;
             ans.push_back(row);
       }
       return ans;

    } 
};