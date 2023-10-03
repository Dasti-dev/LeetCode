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
        vector<vector<int>> sol;
        if(root == NULL)
        return sol;
        queue<TreeNode*> q;
        int flag = 0;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size,0);
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int index;
                if(flag == 0) index = i;
                else index = size - i - 1; 
                level[index] = node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            flag = !flag;
            sol.push_back(level);
        } 
        return sol;
    }
};
