class Solution {
public:
    bool isValid(string s) {
        stack<char> live;
        for (auto ch:s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                live.push(ch);
            } else if (ch == ')') {
                if (live.empty() || live.top() != '('){
                    return false;
                }
                live.pop();
            } else if (ch == ']') {
                if (live.empty() || live.top() != '['){
                    return false;
                }
                live.pop();
            } else if (ch == '}') {
                if (live.empty() || live.top() != '{'){
                    return false;
                }
                live.pop();
            }
        }
        return live.empty();
    }
};
