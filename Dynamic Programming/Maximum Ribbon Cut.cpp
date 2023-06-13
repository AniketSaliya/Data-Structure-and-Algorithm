#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int function(vector<int> &length, int n, int N, vector<vector<int>> &ans) {
    
    for(int i =0;i<n+1;i++) {
        ans[i][0] = 0;
    }
    for(int j =1;j<N+1;j++) {
        ans[0][j] = INT_MIN; // this is because you can not achive any sum of N with 0 length so we assign INT_MIN
    }
    for(int i =1;i<n+1;i++) {
        for(int j =1;j<N+1;j++) {
            if(length[i-1]<=j) {
                ans[i][j] = max(ans[i-1][j], 1 + ans[i][j - length[i-1]]);
            }
            else {
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][N];
}
int main() {
    vector<int> length = {2,3};
    int N =7;
    int n = length.size();
    vector<vector<int>> ans(n+1, vector<int>(N+1));
    int result = function(length, n, N, ans);
    cout << result;
    return 0;
}