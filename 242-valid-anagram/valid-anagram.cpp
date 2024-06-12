class Solution {
public:
    bool isAnagram(string str1, string str2) {
      if (str1.length() != str2.length())
    return false;
 
  int freq[300] = {0};
  for (int i = 0; i < str1.length(); i++)
  {
    freq[str1[i]]++;
  }
  for (int i = 0; i < str2.length(); i++)
  {
    freq[str2[i]]--;
  }
  for (int i = 0; i < 300; i++)
  {
    if (freq[i] != 0)
      return false;
  }
  return true;
}  
    
};