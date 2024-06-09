class Solution {
public:

   int expand(string s , int i , int j){
    int totalcount = 0;
    while( i>=0 && j <= s.length() && s[i]==s[j]){
        totalcount++;
        i--;
        j++;
    }
    return totalcount;

   }
    int countSubstrings(string s) {
        int count = 0;
        for(int centre = 0; centre<s.length(); centre++){
            int odd = expand(s,centre,centre);
            int even = expand(s,centre,centre+1);
             count = count + odd + even;
        }
        return count;
    }
};