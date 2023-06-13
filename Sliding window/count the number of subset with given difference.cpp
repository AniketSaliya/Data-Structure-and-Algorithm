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
    vector<int> nums = {1,1,2,3};  // example input
    int sumofarr = 0;  // example input
    int diff =1;
    for(int i =0;i<nums.size();i++) {
        sumofarr += nums[i];
    }
    int sum = (diff + sumofarr)/2;
    int result = function(nums, sum);
    std::cout << result;
    return 0;
}