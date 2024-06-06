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
// class Solution {
// public:
//     int solve(TreeNode* root, int &maxi)
//     {
//         if(root==NULL)return 0;
//         int lh=solve(root->left,maxi);
//         int rh=solve(root->right,maxi);
//         maxi=max(maxi,lh+rh);
//         return 1+max(lh,rh);
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int maxi=0;
//         int res=solve(root,maxi);
//         return res;
//     }
// };
class Solution {
public:
    int solve(TreeNode* root, int& maxi) {
        if (root == NULL) return 0;
        int lh = solve(root->left, maxi);
        int rh = solve(root->right, maxi);
        maxi = max(maxi, lh + rh); // update the maximum diameter
        return 1 + max(lh, rh);    // return the height of the current node
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0; // initialize the maximum diameter
        solve(root, maxi);
        return maxi; // return the final diameter
    }
};
