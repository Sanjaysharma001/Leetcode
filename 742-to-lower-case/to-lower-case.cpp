class Solution {
public:
    string toLowerCase(string s) {
        int i = 0;
        while(s[i] != '\0'){
            int Currcharacter = s[i];
            if(Currcharacter >= 'A' && Currcharacter<='Z'){
               s[i] =  Currcharacter-'A'+'a';
            }
            i++;
        }
        return s;
    }
};