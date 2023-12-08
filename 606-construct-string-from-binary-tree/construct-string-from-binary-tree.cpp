class Solution {
public:
    void solve(TreeNode* root, string &res) {
        if (root == nullptr) {
            return;
        }
        res.append(to_string(root->val));
        if (root->left != nullptr || root->right != nullptr) {
            res.push_back('(');
            solve(root->left, res);
            res.push_back(')');
        }
        if (root->right != nullptr) {
            res.push_back('(');
            solve(root->right, res);
            res.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string res = "";
        solve(root, res);
        return res;
    }
};
