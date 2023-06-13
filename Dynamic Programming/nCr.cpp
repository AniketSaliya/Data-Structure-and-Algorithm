class Solution{
public:
    int nCr(int n, int r){
        const int MOD = 1000000007; //calculate the answer modulo 10^9+7 thats why i put this MOD.
        vector<vector<int>> ans(n+1, vector<int>(r+1));
        if(n<r)
            return 0;
        else {
            for(int i =0;i<n+1;i++) {
                ans[i][0] = 1;
            }
            for(int j =1;j<r+1;j++) {
                ans[0][j] = 0;
            }
            for(int i =1;i<n+1;i++) {
                for(int j =1;j<r+1;j++) {
                    ans[i][j] = ((ans[i-1][j-1]%MOD) + (ans[i-1][j]%MOD))%MOD;
                }
            }
        }
        return ans[n][r];
    }
};

// n = 778 r = 116