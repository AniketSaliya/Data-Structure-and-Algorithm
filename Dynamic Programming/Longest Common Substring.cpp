#include <iostream>
#include <vector>
using namespace std;

int LCS(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> ans(m+1, vector<int>(n+1));
    
    for(int i=0;i<m+1;i++) {
        for(int j=0;j<n+1;j++) {
            if(i ==0 || j==0) {
                ans[i][j] =0;
            }
        }
    }
    
    for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {
            if(s[i-1] == t[j-1]) {
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else {
                ans[i][j] = 0;
            }
        }
    }
    int maxi=0;
    for(int i=0;i<m+1;i++) {
        for(int j=0;j<n+1;j++) {
            maxi = max(maxi, ans[i][j]);
        }    
    }
    return maxi;
}

int main() {
    string s = "anikets";
    string t = "aniket";
    int res = LCS(s,t);
    cout << res;

    return 0;
}