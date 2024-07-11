
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string temp = "";
        
        for(char c : s) {
            if(c == '(') {
                stk.push(temp);
                temp = "";
            } else if(c == ')') {
                reverse(temp.begin(), temp.end());
                if(!stk.empty()) {
                    temp = stk.top() + temp;
                    stk.pop();
                }
            } else {
                temp += c;
            }
        }
        
        return temp;
    }
};