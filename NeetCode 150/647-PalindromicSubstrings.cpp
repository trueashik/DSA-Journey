class Solution {
    // Here iI have used expand around centre with TC O(n^2) & SC O(1)
public:
    int pdm(string& s, int l, int r){
        int ans = 0;
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            ans++;
            l--;
            r++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            ans += pdm(s, i, i) + pdm(s, i, i+1);
        }
        return ans;
        
    }
};