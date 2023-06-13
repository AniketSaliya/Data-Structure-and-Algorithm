//bottom up approach
#include <iostream>
using namespace std;
#include <vector>

int function(vector<int> nums, int sum) {
    int n = nums.size();
    vector<vector<int>> ans (n+1, vector<int>(sum+1));
    for(int i =0;i<n+1;i++) {
        ans[i][0] = 1;
    }
    for(int j =1;j<sum+1;j++) {
        ans[0][j] = 0;
    }
    for(int i =1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(nums[i-1] <=j) {
                ans[i][j] = ans[i-1][j] + ans[i-1][j - nums[i-1]];
            }
            else if(nums[i-1]>j) {
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][sum];
}
int main() {
    vector<int> nums = {2,3,5,6,8,10};  // example input
    int sum = 10;  // example input
    int result = function(nums, sum);
    std::cout << result;
    return 0;
}

//top-down approach memoization
#include <iostream>
using namespace std;
#include <vector>

int function(vector<int> nums, int sum, int n, vector<vector<int>> &ans) {
    if(sum ==0) {
        return 1;
    }
    if(n ==0) {
        return 0;
    }
    if(ans[n][sum] != 0) {
        return ans[n][sum];
    }
    
    if(nums[n-1] <=sum) {
        return ans[n][sum] = function(nums, sum, n-1, ans) + function(nums,sum- nums[n-1], n-1, ans);
    }
    else{
        return ans[n][sum] = function(nums, sum, n-1, ans);
    }
}
int main() {
    vector<int> nums = {2,3,5,6,8,10};  // example input
    int sum = 10;  // example input
    int n = nums.size();
    vector<vector<int>> ans (n+1, vector<int>(sum+1, 0));
    int result = function(nums, sum, n, ans);
    std::cout << result;
    return 0;
}