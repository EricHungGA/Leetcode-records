class Solution {
public:
    string reverseWords(string s) {
        // two pointers, one from the beginning of a word, one at the end
        // identify words by the presence of spaces
        string result;
        int l = s.size() - 1;
        int r = s.size() - 1;
        while(r >= 0){
            // increment right until we hit a letter (skips all spaces)
            while(r >= 0 && s[r] == ' ' ) r--;
            l = r;
            // find end of the current word
            while(l >= 0 && s[l] != ' ') l--;
            // now add word into our string result
            result = result + s.substr(l + 1,r - l);
            r = l;
            // add space after each word we added if its not the last word
            while (r >= 0 && s[r] == ' ') r--;
            if(r >= 0) result = result + " ";

        }
        return result;
    }
};