class Solution {
public:
    TreeNode * solver(vector<int> & nums ,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode * node=new TreeNode(nums[mid]);
        node->left=solver(nums,s,mid-1);
        node->right=solver(nums,mid+1,e);
        return node;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solver(nums,0,nums.size()-1);
    }
};