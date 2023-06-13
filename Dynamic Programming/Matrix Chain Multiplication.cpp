class Solution{
public:
    int static t[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        memset(t, -1, sizeof(t));
        int i=1;
        int j =N-1;
        return solve(arr, i, j);
    }
    int solve(int arr[], int i, int j) {
        int mini =INT_MAX;
        if(i>=j) 
            return 0;
            
        if(t[i][j] != -1) {
            return t[i][j];
        }
        
        for(int k=i;k<j;k++) {
            int temp = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
            mini = min(mini, temp);
        }
        return t[i][j] = mini;
    }
};
int Solution::t[101][101];


int main() {
    int N = 4;
    int arr[N] = {10, 20, 30, 40};

    Solution solution;
    int result = solution.matrixMultiplication(N, arr);

    std::cout << "Minimum number of multiplications: " << result << std::endl;

    return 0;
}
