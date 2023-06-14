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
    bool isvalid(TreeNode* root, long long min, long long max) {
        if(root == NULL) 
            return true;
        if(root->val <min || root->val >max)
            return false;
        return isvalid(root->left, min, root->val-1LL)&&isvalid(root->right, root->val + 1LL, max);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root, LLONG_MIN, LLONG_MAX);
    }
};

//time: O(N)
//Space: O(N)