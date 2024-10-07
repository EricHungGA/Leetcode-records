class Solution {
public:
    bool isPalindrome(string s) {
        // first convert all letters to lowercase
        std::transform(s.begin(),s.end(),s.begin(),::tolower);
        // two pointers, one from left the other from right
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            // check if its NOT alphanum
            while(l < r && !isalnum(s[l]))l++;
            while(l < r && !isalnum(s[r]))r--;
            // now compare characters
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};