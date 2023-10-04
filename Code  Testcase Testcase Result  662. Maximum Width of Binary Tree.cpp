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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;
        int width = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int first , last;
            for(int i = 0 ; i < size ; i++)
            {
                int cur = q.front().second-min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur;
                if(i==size-1) last = cur;
                if(node->left != NULL) q.push({node->left,(long long)cur*2+1});
                if(node->right != NULL) q.push({node->right,(long long)cur*2+2});
            }
            width = max(width,last-first+1);
        }
        return width;
    }
};
