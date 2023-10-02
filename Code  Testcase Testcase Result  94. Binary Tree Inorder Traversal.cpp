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
private:
    void in(TreeNode* root,vector<int> &sol)
    {
        if(root == NULL)
        return;
        in(root->left,sol);
        sol.push_back(root->val);
        in(root->right,sol);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        in(root,ans);
        return ans;
    }
};
