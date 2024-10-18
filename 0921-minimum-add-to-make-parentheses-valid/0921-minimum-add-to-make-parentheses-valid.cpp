class Solution {
public:
    int minAddToMakeValid(string s) {
        // edge case
        if(s.size() == 0)return 0;
        stack<char> myStack;
        for(int i = 0; i < s.size(); i++){
            if(myStack.empty()){
                myStack.push(s[i]);

            } else {
                if(myStack.top() == '(' && s[i] == ')'){
                    // this completes a paren
                    myStack.pop();
                } else {
                    myStack.push(s[i]);
                }
            }
        }
        return myStack.size();
    }
};