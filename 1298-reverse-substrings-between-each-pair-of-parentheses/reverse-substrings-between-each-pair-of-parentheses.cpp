class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastskipLength;

        string ans;

        for(char &ch : s){
            if(ch=='('){
                lastskipLength.push(ans.length());
            } else if (ch ==')'){
                int S2 =lastskipLength.top();
                lastskipLength.pop();
                reverse(begin(ans) + S2, end(ans));
            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};