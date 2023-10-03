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
    bool sym(TreeNode* p,TreeNode* q)
    {
        if(p==NULL)
        return (p==q);
        if(q==NULL)
        return (q==p);
        return (p->val == q->val) && sym(p->left,q->right) && sym(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* p = root->left;

        TreeNode* q = root->right;
        bool var = sym(p,q);
        return var;
    }
};
