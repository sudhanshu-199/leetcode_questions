class Solution {
public:
    int solve(const string s, int l, int r, int k) {
        if(r - l < k) return 0;
        vector<int> freq(26,0);
        for(int i=l;i<r;i++){
            freq[s[i]-'a']++;
        }
        while(r > l && freq[s[r-1] - 'a'] < k){
            freq[s[r-1]-'a']--;
            r--;
        }
        for(int i=l;i<r;i++){
            if(freq[s[i]-'a']<k){
                return max(solve(s,l,i,k),solve(s,i+1,r,k));
            }
        }
        return r-l;
    }
    int longestSubstring(string s, int k) {
        return solve(s,0,s.size(),k);
    }
};