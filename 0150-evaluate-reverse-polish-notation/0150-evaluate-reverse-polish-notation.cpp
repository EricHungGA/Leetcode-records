class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // edge case
        if(tokens.size() == 0)return 0;
        // so read from left to right, add nums into a stack
        // once we hit an operator, perform operation on 2 most recent nums, aka top of stack
        stack<int>my_stack;
        int right;
        int left;
        int result;
        for(int i = 0; i < tokens.size(); i++){
            // first check if its an operator
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                // now perform operations
                right = my_stack.top(); my_stack.pop();
                left = my_stack.top(); my_stack.pop();
                if(tokens[i] == "+"){
                    result = left + right;
                    my_stack.push(result);
                } else if(tokens[i] == "-"){
                    result = left - right;
                    my_stack.push(result);
                } else if(tokens[i] == "/"){
                    result = left / right;
                    my_stack.push(result);
                } else if(tokens[i] == "*"){
                    result = left * right;
                    my_stack.push(result);
                }
            } else {
                my_stack.push(stoi(tokens[i]));
            }
        }
        return my_stack.top();
    }
};