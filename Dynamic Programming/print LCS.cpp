#include <iostream>
#include <vector>
using namespace std;

string LCS(string s, string t) {
    int m = s.length();
    int n = t.length();
    string a;
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
                ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
            }
        }
    }
    
    int i =m; int j =n;
    while(i>0 && j>0) {
        if(s[i-1] == t[j-1]) {
            a.push_back(s[i-1]);
            i--; j--;
        }
        else {
            if(ans[i][j-1] >ans[i-1][j])
                j--;
            else
                i--;
        }
    }
    int x=0; int y= a.length()-1;
    while(x<=y) {
        char temp = a[x];
        a[x] = a[y];
        a[y] = temp;
        x++;
        y--;
    }
    return a;
}

int main() {
    string s = "acbcf";
    string t = "abcdaf";
    string res = LCS(s,t);
    cout << res;

    return 0;
}