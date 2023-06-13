#include <iostream>
using namespace std;
#include <vector>

int function(vector<int> length, vector<int> price, int N) {
    int n = length.size();
    vector<vector<int>> ans (n+1, vector<int>(N+1));
    for(int i =0;i<n+1;i++) {
        ans[i][0] = 0;
    }
    for(int j =1;j<N+1;j++) {
        ans[0][j] = 0;
    }
    for(int i =1;i<n+1;i++) {
        for(int j=1;j<N+1;j++) {
            if(length[i-1] <=j) {
                ans[i][j] = max(price[i-1] + ans[i][j - length[i-1]], ans[i-1][j]);
            }
            else if(price[i-1]>j) {
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][N];
}
int main() {
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10,17,17,20};  // example input
    int N = 8;
    int result = function(length, price, N);
    std::cout << result;
    return 0;
}