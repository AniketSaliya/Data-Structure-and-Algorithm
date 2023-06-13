
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> ans(m+1, vector<int>(n+1));
        for(int i=0;i<m+1;i++) {
            for(int j=0;j<n+1;j++) {
                if(i ==0 || j==0) {
                    ans[i][j] = 0;
                }
            }
        }
        for(int i=1;i<m+1;i++) {
            for(int j=1;j<n+1;j++) {
                if(str1[i-1] == str2[j-1]) {
                    ans[i][j] = 1 + ans[i-1][j-1];
                }
                else {
                    ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
                }
            }
        }
        return (m+n)-ans[m][n];
    }
};

int main() {
    string str1 = "abac";
    string str2 = "cab";
    Solution sol;
    int res = sol.shortestCommonSupersequence(str1, str2);
    cout << res;

    return 0;
}