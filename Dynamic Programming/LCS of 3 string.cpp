#include <iostream>
#include <vector>
using namespace std;
class solution {
public:
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> ans(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, 0)));
    
    for(int i=1;i<n1+1;i++) {
        for(int j=1;j<n2+1;j++) {
            for(int k=1;k<n3+1;k++) {
                if(A[i-1]==B[j-1] && A[i-1]==C[k-1]) {
                    ans[i][j][k] = 1 + ans[i-1][j-1][k-1];
                }
                else {
                    ans[i][j][k] = max(max(ans[i-1][j][k], ans[i][j-1][k]), ans[i][j][k-1]);
                }
            }
        }
    }
    return ans[n1][n2][n3];
}
};
int main() {
    string A = "geeks";
    string B = "geeksfor";
    string C = "geeksforgeeks";
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();
    solution sol;
    int res = sol.LCSof3(A, B, C, n1, n2, n3);
    cout << res;

    return 0;
} // time and memory efficient











//time and memory consuming:
#include <iostream>
#include <vector>
using namespace std;
class solution {
public:
string LCS (string &ss, string &sss) {
    string s;
    int m = ss.length();
    int n = sss.length();
    vector<vector<int>> ans(m+1, vector<int>(n+1, 0));
    
    for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {
            if(ss[i-1] == sss[j-1]) {
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else {
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }
    int i=m; int j=n;
    while(i>0 && j>0) {
        if(ss[i-1] == sss[j-1]) {
            s.push_back(ss[i-1]);
        }   
        else {
            if(ans[i-1][j] > ans[i][j-1]) 
                i--;
            else
                j--;
        }
    }
    int k =0; int l= s.length();
    while(k<=l) {
        char temp = s[k];
        s[k] = s[l-1];
        s[l-1] = temp;
        k++;
        l--;
    }
    return s;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    string a = LCS(A, B);
    string b = LCS(a, C);
    int c = b.length();
    return c;
}
};
int main() {
    string A = "geeks";
    string B = "geeksfor";
    string C = "geeksforgeeks";
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();
    solution sol;
    int res = sol.LCSof3(A, B, C, n1, n2, n3);
    cout << res;

    return 0;
}