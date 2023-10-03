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
    int path(TreeNode* root, int &maxi)
    {
        if(root == NULL)
        return 0;

        int lh = max(0,path(root->left,maxi));
        int rh = max(0,path(root->right,maxi));

        int sum = root->val + lh + rh;

        maxi = max(sum,maxi);

        return root->val+max(lh,rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        return root->val;
        int max = INT_MIN;
        int pathSum = path(root,max);
        return max;
    }
};
