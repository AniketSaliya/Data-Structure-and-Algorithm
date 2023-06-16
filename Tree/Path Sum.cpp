//112

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
    bool DFS(TreeNode* root, int targetsum, int sum) {
        if(root == nullptr)
            return false;
        if(root->left == NULL && root->right == NULL && root->val + sum == targetsum) 
            return true;
        if(root->right == NULL && root->left == NULL && root->val + sum != targetsum)
            return false;
        
        sum = sum + root->val;
        bool left = DFS(root->left, targetsum, sum);
        bool right = DFS(root->right, targetsum, sum);
        if(left || right)
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        return DFS(root, targetSum, sum);
    }   
};