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
    void post(TreeNode* root,int level,vector<int> &sol)
    {
        if(root==NULL)
        return;
        if(level == sol.size())
        sol.push_back(root->val);

        if(root->right != NULL) post(root->right,level+1,sol);
        if(root->left != NULL) post(root->left,level+1,sol);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        post(root,0,sol);
        return sol;
    }
};
