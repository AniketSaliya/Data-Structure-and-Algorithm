/*f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, so only 1 way so  we recur 
   for remaining i.e f(n - 1)   or you can say 1*f(n-1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. So apart from the 2 people forming a pair for remaining n-2 persons we We get (n - 1) * f(n - 2) ways

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)*/


class Solution: {
public:
    int countFriendsPairings(int n) {
        const int MOD = 1000000007;
        vector<long long> ans(n + 1, 0);
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            ans[i] = ((1 * ans[i - 1]) % MOD + ((i - 1) * ans[i - 2]) % MOD) % MOD;
        }
        return static_cast<int>(ans[n]);
    }   
}; // O(n) space

int countFriendsPairings(int n) 
{ 
   if(n<=2) return n;
   int a =1, b = 2, c = 2;
   for(int i=3;i<=n;i++){
      c = 1*b + (i-1)*(a);
      a = b;
      b = c;
   }
   return c;
} // O(1)space