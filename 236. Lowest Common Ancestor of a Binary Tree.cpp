/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* trav(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root == NULL || root == p || root == q)
        return root;
        TreeNode* lh = trav(root->left,p,q);
        TreeNode* rh = trav(root->right,p,q);
        if(lh == NULL)
        return rh;
        else if(rh == NULL)
        return lh;
        else 
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = trav(root,p,q);
        return node;
    }
};
