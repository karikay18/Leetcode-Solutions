/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(vector<int>& v, TreeNode* root) {
        if (root == nullptr) return;
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }

    TreeNode* solve(vector<int>& v, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = solve(v, start, mid - 1);  // Correct range for left child
        node->right = solve(v, mid + 1, end);  // Correct range for right child
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(v, root);
        return solve(v, 0, v.size() - 1);
    }
};