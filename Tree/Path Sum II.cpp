//113

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        DFS(root, targetSum, ans, res);
        return res;
    }
    void DFS(TreeNode* root, int remainingsum, vector<int> &ans,vector<vector<int>>& res) {
        if(root == nullptr)
            return;
        ans.push_back(root->val);
        if(root->left == nullptr && root->right ==nullptr && remainingsum == root->val) 
            res.push_back(ans);

            DFS(root->left, remainingsum - root->val, ans, res);
            DFS(root->right, remainingsum - root->val, ans, res);
        ans.pop_back();
    }
};