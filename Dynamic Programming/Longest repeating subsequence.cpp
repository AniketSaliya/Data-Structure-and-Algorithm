#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
        int LongestRepeatingSubsequence(string str) {
		    string t = str;
		    int m = str.length();
		    int n = t.length();
		    vector<vector<int>> ans((m+1), vector<int>(n+1));
		    for(int i=0;i<m+1;i++) {
		        for(int j =0;j<n+1;j++) {
		            if(i==0 ||j==0) 
		                ans[i][j] =0;
		        }
		    }
		    
		    for(int i=1;i<m+1;i++) {
		        for(int j=1;j<n+1;j++) {
		            if(str[i-1] == t[j-1] && i != j) {
		                ans[i][j] = 1 + ans[i-1][j-1];
		            }
		            else {
		                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
		            }
		        }
		    }
		    return ans[m][n];
		}
};

int main() {
    string str = "axxzxy";
    solution sol;
    int res = sol.LongestRepeatingSubsequence(str);
    std::cout << res;
    return 0;
}