//1161

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsum = INT_MIN;
        int level = 0;
        int ans = -1;
        if(root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            level++;

            int size = q.size();
            int sum = 0;

            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();

                sum = sum + node->val;
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)    
                    q.push(node->right);
            }

            if(sum > maxsum) {
                ans = level;
                maxsum = sum;
            }
        }
        return ans;
    }
};