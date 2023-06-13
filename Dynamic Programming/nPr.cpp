#include <iostream>
using namespace std;
#include <vector>
int function(int n, int k) {
    vector<vector<int>> ans(n+1, vector<int>(k+1));
    for(int i =0;i<n+1;i++) {
        ans[i][0] = 1;
    }
    for(int j=1;j<k+1;j++) {
        ans[0][j] = 0;
    }
    for(int i =1;i<n+1;i++) {
        for(int j=1;j<k+1;j++) {
            ans[i][j] = (j * ans[i-1][j-1]) + ans[i-1][j];
            // P(n, k) = P(n-1, k) + k* P(n-1, k-1) based on this formula.
        }
    }
    return ans[n][k];
}
int main() {
    int n = 10; int k =3;
    cout << function(n,k);
    return 0;
} //O(n*k) time and space


#include <iostream>
using namespace std;
#include <vector>
int function(int n, int k) {
    int p =1;
    for(int i =0;i<k;i++) {
        p *= (n-i);
    }
    return p;
}
int main() {
    int n = 10; int k =3;
    cout << function(n,k);
    return 0;
}//O(n) time and O(1) space