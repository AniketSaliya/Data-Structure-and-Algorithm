#include <iostream>
#include <vector>
using namespace std;

int minDeletions(string str, int n) { 
    string t;
    for(int i=n-1;i>=0;i--) {
        t.push_back(str[i]);
    }
    vector<vector<int>> ans(n+1, vector<int>(n+1));
    for(int i=0;i<n+1;i++) {
        for(int j=0;j<n+1;j++) {
            if(i==0||j==0){
                ans[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++) {
            if(str[i-1] == t[j-1]) {
                ans[i][j] = 1+ ans[i-1][j-1];
            }
            else {
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }
    return n -ans[n][n];
} 

int main() {
    string str = "aebcbda";
    int n =7;
    int res = minDeletions(str, n);
    std::cout << res;

    return 0;
}