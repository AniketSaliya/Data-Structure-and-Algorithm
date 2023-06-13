class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i =0; int j =0;
        int maxi =0;
        unordered_map<char,int> mp;
        
        while(j <s.size()) {
            mp[s[j]]++;
            int count = mp.size();
            if(count <k) {
                j++;
            }
            else if(count == k) {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(count >k) {
                while(count >k) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        count--;
                    }
                    i++;
                }
                j++;
            }
        }
    return maxi;
    }
};
