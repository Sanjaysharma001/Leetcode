class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int result = 0;
        int oddCount = 0;
        mp[oddCount] = 1;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            oddCount += (nums[i]%2);
            if(mp.count(oddCount-k)){
                result += mp[oddCount-k];
            }
            mp[oddCount]++;
        }
        return result;
    }
};