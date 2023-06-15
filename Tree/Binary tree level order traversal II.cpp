//107

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int level =0;
        queue<TreeNode*> q;
        q.push(root);

        if(root == nullptr)
            return ans;

        while(!q.empty()) {
            level++;
            int size = q.size();
            vector<int> res;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();

                res.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(res);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};