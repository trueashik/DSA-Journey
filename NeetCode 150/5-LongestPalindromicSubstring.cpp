class Solution {
// Here I have used the center expansion method with TC O(n^2) and SC O(1)
public:
    void ispdm(string& s, int l, int r, int& maxlen, int& start){
        while(l >= 0 && r < s.length() && s[l] == s[r]){ 
            if(maxlen < r-l+1) maxlen = r-l+1, start = l;         
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
            if(s.length() <= 1) return s;
            int start, maxlen = 0;
            for(int i = 0; i < s.length(); i++){
                ispdm(s, i, i, maxlen, start);
                if(i < s.length() - 1) ispdm(s, i, i+1, maxlen, start);
            } 
            return s.substr(start, maxlen);
    
        
    }
};