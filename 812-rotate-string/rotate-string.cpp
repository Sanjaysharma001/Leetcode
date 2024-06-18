class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself to check all rotations
        string ans = s + s;
        
        // Check if goal is a substring of doubleS
        if (ans.find(goal) != string::npos) {
            return true;
        } else {
            return false;
        }
    }
    
};