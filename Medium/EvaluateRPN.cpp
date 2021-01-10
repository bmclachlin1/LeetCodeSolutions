class Solution {
public:
    
    int toint(string s) {
        stringstream ss(s);
        int x = 0;
        ss >> x;
        return x;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s=="+" || s=="-" || s=="*" || s=="/") {
                int ans;
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                if (s=="+") {
                    ans = num1 + num2;
                } else if (s == "-") {
                    ans = num1 - num2;
                } else if (s == "*") {
                    ans = num1 * num2;
                } else {
                    ans = num1 / num2;
                }
                stk.push(ans);
            } else {
                stk.push(toint(s));
            }
        }
        return stk.top();
    }
};