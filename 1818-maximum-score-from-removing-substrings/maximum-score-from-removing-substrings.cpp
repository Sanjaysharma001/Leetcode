class Solution {
public:
        
    string removeSubstr(string &s , string &matchStr){
        stack<char> st;

        for(char &Ch: s){
            if(Ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]){
                st.pop();
            } else {
                st.push(Ch);
            }
        }

        string temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(begin(temp), end(temp));
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        
        int n = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        string temp_first = removeSubstr(s, maxStr);
        int l = temp_first.length();

        int charRemoved = (n - l);

        score += (charRemoved / 2) * max(x, y);

        string temp_Sec = removeSubstr(temp_first, minStr);
        charRemoved = l - temp_Sec.length();

        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};
