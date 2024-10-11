class Solution {
private:
    bool palindromeCheck(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        // created helper func above for checking palindrome
        // just call it "recursively" once with the mistake char skipped over
        int mistakes = 0;
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                // running checks on both scenarios for one mistake left, or one right
                return palindromeCheck(s,l + 1, r) || palindromeCheck(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
        
    }
};